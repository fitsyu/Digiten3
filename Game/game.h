#ifndef GAME_H
#define GAME_H

#include "gamemenu.h"
#include "darkshield.h"

#include <QThread>
#include <QMediaPlayer>

#include <actorNode.h>
#include <collisionTraverser.h>
#include <linearVectorForce.h>
#include <physicsCollisionHandler.h>
#include <physicsManager.h>
#include <pandaFramework.h>

#include <cLerpNodePathInterval.h>
#include <cIntervalManager.h>
#include <cMetaInterval.h>

class Game : public QThread
{
    Q_OBJECT

public:
    Game(int& argc, char *argv[], QObject *parent = 0);
    ~Game();

public slots:
    void startGame(QMap<QString, int> configuration);
    void stopGame();
    void pauseGame();
    void resumeGame();
    void resetGame(); // playAgain
    void setupNewGame();


    // player motion
    void handleGesture(int G_ID);

    // remote button
    void handleRemoteButtonPress(QByteArray buttonTxt);


signals:
    void a_pressed();
    void b_pressed();
    void c_pressed();
    void d_pressed();

    void finished(QPrivateSignal);

protected:
    void run();
    static void stopGame(const Event *ev, void* data);
    static void pauseGame(const Event *ev, void* data);

    GameMenu* menu;

private:
    // framework
    PandaFramework   framework;
    WindowFramework* pandaWindow;
    bool _inGame;
    bool _gamePaused;
    void initP3DFramework(int &argc, char **&argv);
    void openUpWindow();

    // nature
    CollisionTraverser*         cTrav;
    CollisionHandlerEvent*      notifier2;
    PhysicsCollisionHandler*    notifier;
    PhysicsManager*             nature;
    AsyncTaskManager*           taskMgr;
    LinearVectorForce*          gravity_force;
    void                        initNature();

    static AsyncTask::DoneStatus rotateTheEarth     (GenericAsyncTask*, void* data);
    static AsyncTask::DoneStatus enableParticles    (GenericAsyncTask *, void* data);
    static void ballIn          (const Event* , void* data);
    static void ballOut         (const Event* , void* data);
    static void ballNet         (const Event* , void* data);
    static void ballTouchesSkin (const Event* , void* data);



    // MODELS
    NodePath render;
        // configuration
        unsigned int characterNumber;
        unsigned int venueNumber;

        // players
        NodePath                    player1, player2;
        NodePath                    p1Range, p2Range;
        AnimControlCollection       animations;
        NodePath add_player     (const string &model_name);
        NodePath expose_joint   (NodePath& model, const string &jointName);

        static void handleKeyEvent(const Event* event, void* data);

        // player move
        void do_service();
        void do_forehand();
        void do_backhand();


        // for p1 (user character). also need for p2?
        AnimControl* serviceAnimation;
        AnimControl* forehandAnimation;
        AnimControl* backhandAnimation;
        AnimControl* runningAnimation;
        AnimControl* neutralAnimation;

        // computer move
        void ai_service();
        void ai_forehand();
        void ai_backhand();

        // run interval
        CLerpNodePathInterval* posInterval;
        CLerpNodePathInterval* hprInterval;
        CMetaInterval* runningInterval;
        CIntervalManager* intervalMgr;


        static void atMiddleCourt(const Event*, void* data);


        // ball
        ActorNode* ballActor;
        NodePath physicalBall;
        LinearVectorForce* bounce_force; bool bounceForceRemoved;
        LinearVectorForce* up_force;
        LinearVectorForce* front_force;

        float distToP1;
        float distToP2;
        bool p1CanStrike;
        bool p2CanStrike;
        bool p1Stroke;
        bool p2Stroke;

        void makeNewBall();

        // instruction
//        PT(TextNode) onScreenText;
        TextNode* scoreText;
        TextNode* instructions;

    int p1Score;
    int p2Score;
    void judge();
    QString translateScore(const int score);
    QMediaPlaylist *shoutScore();
    bool blockingGesture;


    void initModels();

    QUrl strokeSound;
    QUrl bounceSound;
    QUrl loveSound;
    QUrl fifteenSound;
    QUrl thirtySound;
    QUrl fourtySound;
    QUrl allSound;

    QMediaPlayer*   soundPlayer;
    DarkShield* darkShield;

    bool newGameServed;

    // ground & net
    NodePath ground;



    // environments setup
    void loadBeachEnvironment();
    void loadSpaceEnvironment();
    void loadICityEnvironment();

private slots:
    void shot();
    void runToMiddleCourt();
    void followTheBall();
    void clearUpForce();

    void blockGesture();
    void unblockGesture();

};

#endif // GAME_H
