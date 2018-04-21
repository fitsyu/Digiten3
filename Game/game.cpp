#include "game.h"

// Qt's headers
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QMediaPlaylist>
#include <QTime>
#include <QTimer>

// P3D's headers
#include <actorNode.h>
#include <collisionPlane.h>
#include <collisionSphere.h>
#include <forceNode.h>
#include <linearEulerIntegrator.h>
#include <linearVectorForce.h>
#include <auto_bind.h>
#include <character.h>

#define FIELDS_WIDTH 5
#define FIELDS_LONG  30

#define DEFAULT_FRONTFORCE 20
#define DEFAULT_UPFORCE 18
#define DEFAULT_UPTIME  450


Game::Game(int &argc, char *argv[], QObject *parent)
    : QThread(parent),
      _inGame(true),
      _gamePaused(false),
      newGameServed(false),
      p1CanStrike(false),
      p2CanStrike(false),
      p1Stroke(false),
      p2Stroke(false),
      p1Score(0),
      p2Score(0),
      bounceForceRemoved(true)
{
    qDebug() << "initializing game..";
    initP3DFramework(argc, argv);

    // =======
    strokeSound  = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/stroke.ogg");
    bounceSound  = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/bounce.ogg");
    loveSound    = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/love.ogg");
    fifteenSound = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/fifteen.ogg");
    thirtySound  = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/thirty.ogg");
    fourtySound  = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/fourty.ogg");
    allSound     = QUrl::fromLocalFile(qApp->applicationDirPath()+"/sound/all.ogg");


    soundPlayer = new QMediaPlayer(this);
    //    soundPlayer->setPlaylist(soundList);

    soundPlayer->setMedia(strokeSound);
    soundPlayer->setVolume(100);


    darkShield = new DarkShield;
    darkShield->hide();
    connect( this, SIGNAL(a_pressed()), darkShield, SIGNAL(a_pressed()) );
    connect( this, SIGNAL(b_pressed()), darkShield, SIGNAL(b_pressed()) );
    connect( this, SIGNAL(c_pressed()), darkShield, SIGNAL(c_pressed()) );
    connect( this, SIGNAL(d_pressed()), darkShield, SIGNAL(d_pressed()) );
    connect( this, SIGNAL(finished()), darkShield, SLOT(close()));

    blockingGesture = false;
    connect( darkShield, SIGNAL(appeared()), this, SLOT(blockGesture()) );
    //    connect( darkShield, SIGNAL(disappeared()), this, SLOT(unblockGesture()) );

    qDebug() << "game initialized";
}

Game::~Game()
{
    qDebug() << "destroying panda3d framework...";
//    framework.close_framework();
}

void Game::startGame(QMap<QString, int> configuration)
{
    qDebug() << "starting game";
    characterNumber = configuration.value("player");
    venueNumber     = configuration.value("venue");
    _inGame = true;
    unblockGesture();
    start();
    qDebug() << "game started";
}

void Game::stopGame()
{
    qDebug() << "stopping game";
    //    _gamePaused = false;
    framework.close_window(0);

    _inGame = false;

    framework.close_framework();
    qDebug() << "game stopped";
}

/**
 * @brief Game::pauseGame
 * this function should be called when:
 * 1. user explicitly press certain pause button on the controller
 * 2. losing bluetooth connection from controller
 */
void Game::pauseGame()
{
    qDebug() << "pausing game";
    _gamePaused = true;
    darkShield->setTitle("Game Paused");
    darkShield->setInfo("[ b ] Back to Game\n"
                        "[ c ] Exit to Menu");
    darkShield->surprise();

    connect( darkShield, SIGNAL(b_pressed()), this, SLOT(resumeGame()) );
    connect( darkShield, SIGNAL(c_pressed()), this, SLOT(stopGame())) ;


    qDebug() << "game paused";
}

void Game::resumeGame()
{
    qDebug() << "resuming game";
    darkShield->disappear();
    _gamePaused = false;
    qDebug() << "game resumed";
}

void Game::resetGame()
{
    qDebug() << "resetting game..";
    newGameServed = false;
    p1CanStrike = true;
    p2CanStrike = false;
    p1Stroke = false;
    p2Stroke = false;
    p1Score = 0;
    p2Score = 0;

    scoreText->set_text(QString("SCORE\nplayer 1\t: 0\nplayer 2\t: 0")
                        .toStdString());

    darkShield->disappear();
    _gamePaused = false;
    qDebug() << "game resetted";
}

void Game::setupNewGame()
{
    qDebug() << "setting up new game..";
    // set player1, player2, ball positions

    //  4: 5-1 = field's width - 1
    // 12: field's long

    //    player1.set_pos( -4 + (qrand()% 4),  12, 0 );
    //    player2.set_pos(  0 + (qrand()% 4), -12, 0 );
    player1.set_pos( -2,  12, 0 );
    player2.set_pos(  2, -12, 0 );


    // HOW TO RESET THE BALL???
    physicalBall.remove_node();
    makeNewBall();

    // TODO: x is based on current server
    NodePath current_server = player1;
    physicalBall.set_pos(current_server.get_x(), current_server.get_y()-1, 3.2);

    animations.pose("service", 0);
    newGameServed = false; // set to true after service shot
    //    posInterval->loop();
    qDebug() << "new game set.";
}

/**
 * @brief Game::handleGesture
 * @param G_ID
 * G_ID stands for Gesture ID
 * make the player moves according to this Gesture ID
 */
void Game::handleGesture(int G_ID)
{
    qDebug() << "handling gesture";
    if ( blockingGesture ) {
        qDebug() << "gesture is blocked.";
        return;
    }

    // "too fast gesture detection" protection
    if ( serviceAnimation->is_playing()  ||
         forehandAnimation->is_playing() ||
         backhandAnimation->is_playing() )
    {
        qDebug() << "gesture was performed too fast.";
        return;
    }

    if (!newGameServed){ do_service(); return; }

    switch (G_ID){
    case 1:
        do_forehand();
        break;
    case 2:
        do_backhand();
        break;
    case 3:
        do_service();
        break;
    default:
        break;
    }
    qDebug() << "gesture handled";
}

void Game::handleRemoteButtonPress(QByteArray buttonTxt)
{
    qDebug() << "handling button press";
    if ( buttonTxt == "A" ){
        emit a_pressed();
        return;
    }
    if ( buttonTxt == "B" ){
        emit b_pressed();
        return;
    }
    if ( buttonTxt == "C" ){
        emit c_pressed();
        pauseGame();
    }
    if ( buttonTxt == "D" ){
        emit d_pressed();
        return;
    }

    // forward to darkshield?

    qDebug() << "button press handled.";
}


void Game::openUpWindow()
{
    qDebug() << "opening panda window";
    pandaWindow = NULL;
    taskMgr = AsyncTaskManager::get_global_ptr();
    taskMgr->add(new GenericAsyncTask("mainLoop", rotateTheEarth, this));

    intervalMgr = CIntervalManager::get_global_ptr();

    // -----------------------------
    QDesktopWidget desktop;
    WindowProperties props;

    // window setup
    framework.get_default_window_props(props);
    props.set_size(desktop.width(), desktop.height());
    props.set_fullscreen(true);
    pandaWindow = framework.open_window(props, 0);

    // close event handling
    pandaWindow->get_graphics_window()->set_close_request_event("closing...");
    framework.define_key("closing...", "aboutToClose", &stopGame, this);
    render = pandaWindow->get_render();

    // some more initializations
    initNature();
    initModels();

    qDebug() << "panda window opened.";
}

void Game::run()
{
    qDebug() << "running..";
    openUpWindow();
    // emit game started



    // app.exec !
    _inGame = true;
    _gamePaused = false;    
    Thread* currentThread = Thread::get_current_thread();
    while (_inGame){
        if (!_gamePaused) framework.do_frame(currentThread);
        QApplication::instance()->processEvents();
    }

    qDebug() << "finished.";
    emit finished(QPrivateSignal());
}

void Game::stopGame(const Event *ev, void *data)
{
    qDebug() << "closing....";
    //    static_cast<Game*>(data)->framework.close_window(0);
    //    static_cast<Game*>(data)->_inGame = false;
    Game* self = static_cast<Game*>(data);
    self->stopGame();
}

void Game::pauseGame(const Event *ev, void *data)
{
    Game* self = static_cast<Game*>(data);
    self->pauseGame();
}

void Game::initP3DFramework(int& argc, char**& argv)
{
    framework.open_framework(argc, argv);

}

void Game::initNature()
{
    qDebug() << "init nature...";
    cTrav = new CollisionTraverser;
    notifier = new PhysicsCollisionHandler;
    notifier->add_in_pattern("%fn-in-%in");
    notifier->add_out_pattern("%fn-out-%in");

    framework.define_key("ball-in-ground",  "ballInGround",     ballIn,          this);
    framework.define_key("ball-out-ground", "ballOutGround",    ballOut,         this);
    framework.define_key("ball-in-net",     "ballInNet",        ballNet,         this);

    //    notifier2 = new CollisionHandlerEvent;
    //    notifier2->add_in_pattern  ("%fn-ke-%in");
    //    notifier2->add_out_pattern ("%fn-dari-%in");

    framework.define_key("ball-in-skin",    "ballInSkin",       ballTouchesSkin, this);

    // player move
    framework.define_key("q", "service",  handleKeyEvent, this);
    framework.define_key("w", "forehand", handleKeyEvent, this);
    framework.define_key("e", "backhand", handleKeyEvent, this);

    // computer move
    framework.define_key("i", "Cservice",  handleKeyEvent, this);
    framework.define_key("o", "Cforehand", handleKeyEvent, this);
    framework.define_key("p", "Cbackhand", handleKeyEvent, this);

    // post running to middle
    framework.define_key("iAmAtCenter", "turnMeBack", atMiddleCourt, this);

    // game pause
    framework.define_key("c", "pauseTheGame", pauseGame, this);

    pandaWindow->enable_keyboard();

    nature = new PhysicsManager;
    taskMgr->add(new GenericAsyncTask("enableParticles", enableParticles, this));
    nature->attach_linear_integrator(new LinearEulerIntegrator());

    ForceNode* gravNode = new ForceNode("gravity");
    render.attach_new_node(gravNode);
    gravity_force = new LinearVectorForce(0, 0, -9.81);
    gravNode->add_force(gravity_force);
    nature->add_linear_force(gravity_force);

    qsrand(QTime::currentTime().msec());

    qDebug() << "nature initialized.";
}

/**
 * @brief Game::rotateTheEarth
 * @param task
 * @param data
 * @return
 * Here will be a lot of checks
 */
AsyncTask::DoneStatus Game::rotateTheEarth(GenericAsyncTask * /*task*/, void *data)
{
    Game* self = static_cast<Game*>(data);
    if ( !self->animations.is_playing() ){
        //        self->animations.loop("running", true);
        if (self->newGameServed) self->animations.loop("neutral", true);
        self->animations.loop("neutral.1", true);
    }

    // FOLLOW THE BALL
    if (self->p1Stroke){
        self->player2.set_x(self->physicalBall.get_x());
        //        self->followTheBall();
    }

    if (self->p2Stroke){
        self->player1.set_x(self->physicalBall.get_x());


        //        if ( !self->animations.find_anim("running")->is_playing() ){
        //            self->physicalBall.get_x() > 0 ? self->player1.set_h(90):self->player1.set_h(270);
        //            self->animations.find_anim("running")->set_play_rate(2.0);
        //            self->animations.find_anim("running")->loop(true);
        //        }

    }


    // BOUND CHECK
    if (
            qAbs( self->physicalBall.get_y() ) > FIELDS_LONG
            ||
            qAbs( self->physicalBall.get_x() ) > FIELDS_WIDTH
            )
    {
        qDebug() << "OUT";
        self->judge();
        self->setupNewGame();
    }

    // FIRING RANGE CHECK
    float currentDistance;
    currentDistance = self->player1.get_distance(self->physicalBall);
    if ( self->distToP1 != currentDistance ){
        self->distToP1 = currentDistance;

        // a bit longer than p2 regarding user doing
        if (self->distToP1 < 10){
            self->p1CanStrike = true;
            self->p1Range.show();
        }
        else{
            self->p1CanStrike = false;
            self->p1Range.hide();
        }
    }

    currentDistance = self->player2.get_distance(self->physicalBall);
    if ( self->distToP2 != currentDistance ){
        self->distToP2 = currentDistance;
        if (self->distToP2 < 3) {
            if (self->p2CanStrike == false){ // neccessary otherwise it calls "backhand" often
                self->p2CanStrike = true;
                //                self->ai_backhand();
                self->ai_forehand();
                self->p2Range.show();
            }
        }
        else{
            self->p2CanStrike = false;
            self->p2Range.hide();
        }
    }

    return AsyncTask::DS_cont;
}

AsyncTask::DoneStatus Game::enableParticles(GenericAsyncTask* , void *data)
{
    const double dt = ClockObject::get_global_clock()->get_dt();
    Game* w = static_cast<Game*>(data);
    w->nature->do_physics(dt);      // necessary for physics system
    w->cTrav->traverse(w->render);  // necessary for collision system
    w->intervalMgr->step();         // necessary for interval animation system
    return AsyncTask::DS_cont;
}

void Game::ballIn(const Event *, void *data)
{
    //    qDebug() << "ball in..";
    Game* self = static_cast<Game*>(data);

    if (!self->newGameServed) return;

    self->bounce_force = new LinearVectorForce(0, 0, 150);
    self->ballActor->get_physical(0)->add_linear_force(self->bounce_force);


    self->bounceForceRemoved = false;
}

void Game::ballOut(const Event *, void *data)
{
    //    qDebug() << "ball out..";
    Game* self = static_cast<Game*>(data);

    if (!self->newGameServed) return;

    self->ballActor->get_physical(0)->remove_linear_force(self->bounce_force);

    self->bounceForceRemoved = true;
}

void Game::ballNet(const Event *, void *data)
{
    //    qDebug() << "ball net..";
    Game* self = static_cast<Game*>(data);
    self->judge();
    self->setupNewGame();
}

void Game::ballTouchesSkin(const Event *ev, void *data)
{

    qDebug() << "ball is touching skin.."; // return;
    Game* self = static_cast<Game*>(data);
    //    self->ballActor->get_physical(0)->clear_linear_forces();
    /*
     * if player is doing something:
     *      directionangle = 0
     *      if he do backhand
     *          directionangle = 0 - 90
     *      else
     *          directionangle = 0 + 90
     *      shot the ball at directionangle
     * else
     *      put down the ball
     */
    NodePath player = static_cast<CollisionEntry*>( ev->get_parameter(0).get_ptr() )
            ->get_into_node_path().get_parent();
    if ( player == self->player2 ){
        self->ai_backhand();
    }

}

void Game::handleKeyEvent(const Event *event, void *data)
{
    Game* self = static_cast<Game*>(data);
    string evName = event->get_name();
    if ( evName == "q" ) {
        return self->do_service();
    }
    if ( evName == "w" ) {
        return  self->do_forehand();
    }
    if ( evName == "e" ) {
        return self->do_backhand();
    }
    if ( evName == "i" ) {
        return self->ai_service();
    }
    if ( evName == "o" ) {
        return self->ai_forehand();
    }
    if ( evName == "p" ) {
        return self->ai_backhand();
    }
}

void Game::shot()
{
    ballActor->get_physical(0)->remove_linear_force(up_force);
    ballActor->get_physical(0)->add_linear_force(front_force);

    soundPlayer->setMedia(strokeSound);
    soundPlayer->play();

    newGameServed = true;
    //    posInterval->pause();
    // run to center: common strategy
    //    player1.set_x(0);
}

void Game::do_service()
{
    if (!p1CanStrike) return;

    if (!bounceForceRemoved) ballActor->get_physical(0)->remove_linear_force(bounce_force);


    // throw ball up a bit
    up_force = new LinearVectorForce( 0, 0,  0.8*DEFAULT_UPFORCE);
    ballActor->get_physical(0)->add_linear_force(up_force);




    NodePath receiver = player2;
    front_force = new LinearVectorForce( receiver.get_x(), -DEFAULT_FRONTFORCE, 0);


    AnimControl* serviceAction = animations.find_anim("service");

    int frameRate        = serviceAction->get_frame_rate();
    int frameNum         = serviceAction->get_num_frames();
    int timeRequiredInMs = (frameNum / frameRate) * 1000;



    serviceAction->play();
    QTimer::singleShot(timeRequiredInMs-1000, this, SLOT(shot()));

    //    ballActor->get_physical(0)->add_linear_force(front_force);
    p1Stroke = true;
    p2Stroke = false;

}

void Game::do_forehand()
{
    if (!p1CanStrike) return;
    //270 <- 0
    physicalBall.remove_node();
    makeNewBall();
    physicalBall.set_pos(player1.get_pos());

    front_force = new LinearVectorForce(qrand()%5, -DEFAULT_FRONTFORCE, 0);
    up_force = new LinearVectorForce(0, 0, DEFAULT_UPFORCE);

    player1.set_h(0);
    animations.play("forehand");
    ballActor->get_physical(0)->add_linear_force(front_force);
    ballActor->get_physical(0)->add_linear_force(up_force); // call clear function every time this called somewhere

    p1Stroke = true;
    p2Stroke = false;

    soundPlayer->play();

    //    QTimer::singleShot(1000, this, SLOT(runToMiddleCourt()));
    //    runToMiddleCourt();
    QTimer::singleShot(DEFAULT_UPTIME, this, SLOT(clearUpForce()));
}

void Game::do_backhand()
{
    if (!p1CanStrike) return;
    // 0 -> 90
    physicalBall.remove_node();
    makeNewBall();
    physicalBall.set_pos(player1.get_pos());

    front_force = new LinearVectorForce( -(qrand()%5), -DEFAULT_FRONTFORCE, 0);
    up_force = new LinearVectorForce(0, 0, DEFAULT_UPFORCE);

    player1.set_h(0);
    animations.play("backhand");
    ballActor->get_physical(0)->add_linear_force(front_force);
    ballActor->get_physical(0)->add_linear_force(up_force);

    p1Stroke = true;
    p2Stroke = false;

    soundPlayer->play();


    //    QTimer::singleShot(1000, this, SLOT(runToMiddleCourt()));
    QTimer::singleShot(DEFAULT_UPTIME, this, SLOT(clearUpForce()));
}

void Game::ai_service()
{
    animations.play("service.1");

    p2Stroke = true;
    p1Stroke = false;
}

void Game::ai_forehand()
{
    // 0 -> 90
    physicalBall.remove_node();
    makeNewBall();
    physicalBall.set_pos(player2.get_pos());

    front_force = new LinearVectorForce(-1, DEFAULT_FRONTFORCE, 0);
    up_force = new LinearVectorForce(0, 0, DEFAULT_UPFORCE);

    animations.play("forehand.1");
    ballActor->get_physical(0)->add_linear_force(front_force);
    ballActor->get_physical(0)->add_linear_force(up_force);

    p2Stroke = true;
    p1Stroke = false;

    soundPlayer->play();

    QTimer::singleShot(DEFAULT_UPTIME, this, SLOT(clearUpForce()));
}

void Game::ai_backhand()
{
    // 270 -> 0
    physicalBall.remove_node();
    makeNewBall();
    physicalBall.set_pos(player2.get_pos());

    front_force = new LinearVectorForce( player1.get_x(), 30, 0);

    animations.play("backhand.1");
    ballActor->get_physical(0)->add_linear_force(front_force);

    p2Stroke = true;
    p1Stroke = false;

    soundPlayer->play();
}

/**
 * @brief Game::runToMiddleCourt
 * common strategy in tennis game:
 * each time player shots, she'll go to center of court
 * anticipating the counter-shot from the opponent
 *
 * call this routine every after shot!
 */
void Game::runToMiddleCourt()
{
    player1.get_x(render) > 0 ? player1.set_h(270):player1.set_h(90);

    // feel silly to do this :(
    posInterval = new CLerpNodePathInterval(
                "posInterval", 0.85, CLerpInterval::BT_no_blend,
                false, false, player1, NodePath()
                );

    posInterval->set_end_pos(LPoint3(0, 12, 0));
    posInterval->set_done_event("iAmAtCenter");
    posInterval->start();

    animations.loop("running", true);
}

void Game::followTheBall()
{
    player2.set_x(physicalBall.get_x());
}

void Game::clearUpForce()
{
    ballActor->get_physical(0)->remove_linear_force(up_force);
}

void Game::blockGesture()
{
    qDebug() << "blocking gesture";
    blockingGesture = true;
    qDebug() << "gesture blocked";
}

void Game::unblockGesture()
{
    qDebug() << "unblocking gesture";
    blockingGesture = false;
    qDebug() << "gesture unblocked";
}

void Game::atMiddleCourt(const Event *, void *data)
{
    Game* self = static_cast<Game*>(data);
    self->player1.set_h(0);
    self->animations.stop("running");
}

void Game::makeNewBall()
{
    qDebug() << "making new ball";

    ballActor = new ActorNode("ball-body");
    ballActor->get_physics_object()->set_mass(10);
    physicalBall = render.attach_new_node(ballActor);

    NodePath ballModel = pandaWindow->load_model(physicalBall, "models/tennisball.bam");
    ballModel.set_scale(0.5, 0.5, 0.5);
    physicalBall.set_pos(0, 11, 3.2); //2);

    CollisionNode* ballSkinWarp = new CollisionNode("ball");
    NodePath ballSkin = ballModel.attach_new_node(ballSkinWarp);
    ballSkinWarp->add_solid(new CollisionSphere(0, 0, 0, .25));
    //    ballSkin.show();

    cTrav->add_collider(ballSkin, notifier);
    notifier->add_collider(ballSkin, physicalBall);

    nature->attach_physical_node(ballActor);
    //    front_force = new LinearVectorForce(0, 0, 0);
    //    cTrav->set_respect_prev_transform(true);

    qDebug() << "new ball made.";
}

void Game::judge()
{
    qDebug() << "show scores";

    if ( p1Stroke ) {
        p1Score++;
    } else if (p2Stroke) {
        p2Score++;
    }

    // winner check
    if ( p1Score > 3 || p2Score > 3) {
        p1Score>3?darkShield->setTitle("You win!"):darkShield->setTitle("You lose!");
        darkShield->setInfo(QString("%1 : %2\n"
                                    "[ a ] play Again\n"
                                    "[ b ] Back to menu\n\n"

                                    "thanks for playing")
                            .arg(translateScore(p1Score), translateScore(p2Score))
                            );

        connect( darkShield, SIGNAL(a_pressed()), this, SLOT(resetGame()) );
        connect( darkShield, SIGNAL(b_pressed()), this, SLOT(stopGame())  );

        darkShield->surprise();

        qDebug() << "game won.";

        return;
    }


    scoreText->set_text(QString("SCORE\nplayer 1\t: %1\nplayer 2\t: %2")
                        .arg(translateScore(p1Score), translateScore(p2Score))
                        .toStdString());

    QMediaPlaylist* soundList = shoutScore();
    soundPlayer->setPlaylist(soundList);
    soundPlayer->play();

    connect (soundPlayer, SIGNAL(mediaChanged(QMediaContent)), soundList, SLOT(deleteLater()));

    darkShield->setTitle("== SCORE ==");
    darkShield->setInfo(QString("%1 : %2").arg(translateScore(p1Score), translateScore(p2Score)));
    darkShield->surprise();
    QTimer::singleShot(2000, darkShield, SLOT(disappear()));
    QTimer::singleShot(2000, this, SLOT(unblockGesture()) );


    qDebug() << "score shown.";
}

QString Game::translateScore(const int score)
{
    QString translatedScore;

    switch (score){
    case 0:
        translatedScore = "0";
        break;
    case 1:
        translatedScore = "15";
        break;
    case 2:
        translatedScore = "30";
        break;
    case 3:
        translatedScore = "40";
        break;
    case 4:
        translatedScore = "40+";
        break;
    default:
        break;
    }

    return translatedScore;
}

QMediaPlaylist* Game::shoutScore()
{
    QUrl p1Sound;
    QUrl p2Sound;

    switch (p1Score){
    case 0:
        p1Sound = loveSound;
        break;
    case 1:
        p1Sound = fifteenSound;
        break;
    case 2:
        p1Sound = thirtySound;
        break;
    case 3:
        p1Sound = fourtySound;
        break;
    }

    switch (p2Score){
    case 0:
        p2Sound = loveSound;
        break;
    case 1:
        p2Sound = fifteenSound;
        break;
    case 2:
        p2Sound = thirtySound;
        break;
    case 3:
        p2Sound = fourtySound;
        break;
    }

    if (p1Score == p2Score){
        p2Sound = allSound;
    }

    QMediaPlaylist* soundList = new QMediaPlaylist;
    soundList->addMedia(p1Sound);
    soundList->addMedia(p2Sound);
    return soundList;
}

void Game::initModels()
{
    qDebug() << "initializing models";
    // ============= SCORE =================
    scoreText = new TextNode("node name");
    scoreText->set_text("SCORE\nplayer 1\t: 0\nplayer 2\t: 0");

    NodePath textNodePath = pandaWindow->get_aspect_2d().attach_new_node(scoreText);
    textNodePath.set_scale(0.05);
    textNodePath.set_pos(-1.5, -1, 0.85);

    // ======== INSTRUCTIONS ================
    instructions = new TextNode("instructions");
    instructions->set_text("press c to pause game");
    instructions->set_wordwrap(10);
    instructions->set_align(TextNode::A_right);
    NodePath instructionsNP = pandaWindow->get_aspect_2d().attach_new_node(instructions);
    instructionsNP.set_scale(.05);
    instructionsNP.set_pos(1.5, 0, 0.85);



    // =============== city =======================
    //    NodePath city = pandaWindow->load_model(render, "models/street.bam");
    //    city.set_scale(5, 5 , 5);
    //    city.set_h(270+180);
    //    city.set_pos(-5, 20, -100);
    // ============================================

    // ############### net ########################
    NodePath tennisNet = pandaWindow->load_model(render, "models/tennisnet.bam");
    tennisNet.set_scale(.20, .5, .3);
    tennisNet.set_pos(0, 0, 0);

    NodePath netSolid = tennisNet.find("**/tennisnet");

    netSolid.node()->set_name("net");

    DCAST(CollisionNode, netSolid.node())->set_from_collide_mask( BitMask32::all_off() );

    netSolid.node()->set_into_collide_mask(BitMask32::bit(0));
    //    netSolid.show();
    // ============================================

    //    qDebug() << "venue : #" << venueNumber;
    // =========== ground =========================
//    NodePath ground;


//    loadSpaceEnvironment();
    if      (venueNumber == 1)   loadBeachEnvironment(); //ground = pandaWindow->load_model(render, "models/hardfield.egg");
    else if (venueNumber == 2)   loadSpaceEnvironment(); //ground = pandaWindow->load_model(render, "models/grassfield.egg");
    else if (venueNumber == 3)   loadICityEnvironment(); //ground = pandaWindow->load_model(render, "models/clayfield.egg");
    else loadICityEnvironment(); // default

    //    else     ground = pandaWindow->load_model(render, "models/hardfield.egg");
    //    NodePath ground = pandaWindow->load_model(render, "models/lapangan.bam"); //tenniscourt.bam");
//    ground = pandaWindow->load_model(render, "models/hardfield.egg");
//    ground.set_pos(0, 0, 0);

    CollisionNode* groundSolidWarp = new CollisionNode("ground");
    NodePath groundSolid = ground.attach_new_node(groundSolidWarp);
    groundSolidWarp->add_solid(new CollisionPlane(LPlane(LVector3(0, 0, 1), LPoint3(0, 0, 0))));
    //    NodePath groundSolid = ground.find("**/Plane"); // TODO: remove Plane collision tag later in egg

    DCAST(CollisionNode, groundSolid.node())->set_from_collide_mask( BitMask32::all_off() );
    //    groundSolidWarp->set_from_collide_mask( BitMask32::all_off() );
    groundSolid.node()->set_into_collide_mask(BitMask32::bit(0));
    groundSolid.set_pos(0, 0, 0); //1.25);
    //    groundSolid.show();
    // ============================================

    //    // ============ BALL ==========================
    //    ballActor = new ActorNode("ball-body");
    //    ballActor->get_physics_object()->set_mass(10);
    //    physicalBall = render.attach_new_node(ballActor);

    //    NodePath ballModel = pandaWindow->load_model(physicalBall, "models/tennisball.bam");
    //    ballModel.set_scale(0.5, 0.5, 0.5);
    //    physicalBall.set_pos(0, 11, 3.2); //2);

    //    CollisionNode* ballSkinWarp = new CollisionNode("ball");
    //    NodePath ballSkin = ballModel.attach_new_node(ballSkinWarp);
    //    ballSkinWarp->add_solid(new CollisionSphere(0, 0, 0, .25));
    //    //    ballSkin.show();

    //    cTrav->add_collider(ballSkin, notifier);
    //    notifier->add_collider(ballSkin, physicalBall);

    ////    nature->attach_physical_node(ballActor); // done at setupNewGame
    //    front_force = new LinearVectorForce(0, 0, 0);
    //    // ==============================================

    //  #hit point marker
    //    hitPoint = pandaWindow->load_model(render, "models/HitPoint2.egg");
    //    hitPoint.set_pos(physicalBall.get_pos());

    //    hitPoint.set_scale(.25, .25, .25);

    //    qDebug() << "char #: " << characterNumber;
    // players
    /* export configuration
         *
         * TBS generation:  Panda
         * Tex processing: All checked but Shadow
        */
    player1 = add_player(characterNumber==1?"models/Ali2.bam":"models/Ali2-blue.bam");
    player1.set_name("player1");
    player1.set_pos( 0, 12, 0);

    p1Range = pandaWindow->load_model(player1, "models/highlightron.egg");
    p1Range.set_scale(2,2,2);
    p1Range.hide();


    posInterval = new CLerpNodePathInterval("posInterval",
                                            1,
                                            CLerpInterval::BT_no_blend,
                                            false,
                                            false,
                                            player1,
                                            NodePath()
                                            );
    posInterval->set_start_hpr(LVecBase3(0, 0, 0));
    posInterval->set_end_hpr(LVecBase3(0, 10, 0));

    //    posInterval->set_end_pos(LPoint3(0, 12, 0));
    //    posInterval->set_auto_finish(true);
    //    player1.look_at(-90, 0, 0);

    //    runningInterval = new CMetaInterval("runningInvertal");
    //    runningInterval->add_c_interval(posInterval, 0, CMetaInterval::RS_previous_end);


    player2 = add_player(characterNumber==1?"models/Ali2-blue.bam":"models/Ali2.bam");
    player2.set_name("player2");
    player2.set_pos( 0, -12, 0);
    player2.set_h(180);

    p2Range = pandaWindow->load_model(player2, "models/highlightron.egg");
    p2Range.set_scale(2,2,2);
    p2Range.hide();

    // sometimes it get wrong
    //    animations.get_anim(2)->set_play_rate(2.0);
    //    animations.get_anim(3)->set_play_rate(2.0);
    // to make sure
    for (int a=0; a<animations.get_num_anims(); ++a){
        string animName = animations.get_anim_name(a);
        if ( animName == "forehand" || animName == "forehand.1" ){
            animations.get_anim(a)->set_play_rate(2.0);
            continue;
        }
        if ( animName == "backhand" || animName == "backhand.1" ){
            animations.get_anim(a)->set_play_rate(3.0);
        }
    }


    // for easy access to animations later somewhere in code
    serviceAnimation  = animations.find_anim("service");
    forehandAnimation = animations.find_anim("forehand");
    backhandAnimation = animations.find_anim("backhand");
    runningAnimation  = animations.find_anim("running");
    neutralAnimation  = animations.find_anim("neutral");

    NodePath camera = pandaWindow->get_camera_group();
    //     from top
    //    camera.set_pos(0, 0, 150);
    //    camera.set_p(-90);

    //     from center
    camera.set_pos(0, 30, 3);
    camera.set_h(-180);

    //     from left side
    //    camera.set_pos(-35, 0, 3);
    //    camera.set_h(-90);

    //     slightly tilted
    //    camera.set_pos(5, 20, 3);
    //    camera.set_h(160);

//        pandaWindow->setup_trackball();
    setupNewGame();
    qDebug() << "models initialized";
}

void Game::loadBeachEnvironment()
{
    qDebug() << "setting up the beach";

    NodePath beach = render.attach_new_node("beach");

    /*NodePath laut =*/ pandaWindow->load_model(beach, "the beach/laut.egg");

    NodePath pantai = pandaWindow->load_model(beach, "the beach/pantai.egg");
    pantai.set_two_sided(true);

    /*NodePath pohonan =*/ pandaWindow->load_model(beach, "the beach/pohonan.egg");

    /*NodePath matahari =*/ pandaWindow->load_model(beach, "the beach/matahari.egg");

    /*NodePath langit =*/ pandaWindow->load_model(beach, "the beach/happysky.egg");

    beach.set_scale(3);
    beach.set_h(180);



    ground = pandaWindow->load_model(render, "models/grassfield.egg");

    qDebug() << "the beach set";
}

void Game::loadSpaceEnvironment()
{
    qDebug() << "setting up the space";

    NodePath space = render.attach_new_node("space");

    pandaWindow->load_model(space, "the space/bumi.egg");
    pandaWindow->load_model(space, "the space/bulan.egg");

    NodePath langit = pandaWindow->load_model(space, "the space/langit.egg");
    langit.set_two_sided(true);

    space.set_scale(5);
    space.set_h(180);

    ground = pandaWindow->load_model(render, "models/clayfield.egg");

    qDebug() << "the space set";
}

void Game::loadICityEnvironment()
{
    qDebug() << "setting up the iCity";
    NodePath city = pandaWindow->load_model(render, "models/street.bam");
    city.set_scale(5, 5 , 5);
    city.set_h(270+180);
    city.set_pos(-5, 20, -100);

    ground = pandaWindow->load_model(render, "models/hardfield.egg");

    qDebug() << "the iCity set";
}

NodePath Game::add_player(const string &model_name)
{
    NodePath new_player = pandaWindow->load_model(render, model_name);

    string bamstripped = model_name.substr( 0, model_name.length()-4 );

    pandaWindow->load_model(new_player, bamstripped+"-service.bam");
    pandaWindow->load_model(new_player, bamstripped+"-neutral.bam");
    pandaWindow->load_model(new_player, bamstripped+"-forehand.bam");
    pandaWindow->load_model(new_player, bamstripped+"-backhand.bam");
    pandaWindow->load_model(new_player, bamstripped+"-running.bam");

    auto_bind(new_player.node(), animations, PartGroup::HMF_ok_wrong_root_name);

    //    player1_head = control_joint(player1, "head");
    //    player1_head = control_joint(player1, "head");
    NodePath right_palm = expose_joint(new_player, "palm.R");
    right_palm.set_name("rpalm");

    //    //    #racket
    NodePath racket2 = pandaWindow->load_model(right_palm, "models/tennisracket.bam");

    racket2.set_scale(.5, .5, .5);
    racket2.set_hpr(0, -90, 90);
    racket2.set_pos(.5, 0, .05);




    //    drop_point_hit = false;

    //    CollisionNode* skinGuard = new CollisionNode("skin");
    //    NodePath skinGuardNode = new_player.attach_new_node(skinGuard);
    //    skinGuard->add_solid(new CollisionSphere(0, 0, 0, 1.5));

    //    DCAST(CollisionNode, skinGuardNode.node())->set_from_collide_mask( BitMask32::all_off() );
    //    skinGuardNode.node()->set_into_collide_mask(BitMask32::bit(0));
    //    skinGuardNode.set_pos(0, 0, 1);
    //    skinGuardNode.show();

    return new_player;
}

NodePath Game::expose_joint(NodePath &model, const string &jointName)
{
    bool foundJoint = false;
    NodePath jointNp = model.attach_new_node(jointName);
    NodePath characterNP = model.find("**/+Character");
    PT(Character) characterPtr = DCAST(Character, characterNP.node());
    if(characterPtr != NULL)
    {
        PT(CharacterJoint) characterJointPtr = characterPtr->find_joint(jointName);
        if(characterJointPtr != NULL)
        {
            foundJoint = true;
            characterJointPtr->add_net_transform(jointNp.node());
        }
    }
    if(!foundJoint)
    {
        nout << "ERROR: no joint named `" << jointName << "'." << endl;
        jointNp.remove_node();
    }
    return jointNp;
}
