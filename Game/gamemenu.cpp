#include "gamemenu.h"
#include "ui_gamemenu.h"

#include <QDebug>
#include <QDesktopWidget>
#include <QTimer>
#include <qevent.h>

GameMenu::GameMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameMenu),
    currentFrameIndex(0),
    backgroundMusicPlayer(NULL)
{
    ui->setupUi(this);

    backgroundMusicPlayer = new QMediaPlayer(this);
    buttonClickPlayer     = new QMediaPlayer(this);

    QUrl backgroundMusicUrl = QUrl::fromLocalFile( qApp->applicationDirPath()+"/sound/map space.ogg");  //FlyAway.ogg" );
    backgroundMusicPlayer->setMedia(backgroundMusicUrl);
    backgroundMusicPlayer->setVolume(100);

    connect(backgroundMusicPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
                                          this, SLOT(replayBgMusic(QMediaPlayer::MediaStatus)));


    QUrl buttonClickSoundUrl = QUrl::fromLocalFile( qApp->applicationDirPath()+"/sound/pop.wav");
    buttonClickPlayer->setMedia(buttonClickSoundUrl);
    buttonClickPlayer->setVolume(100);

    adjustFrames();

    //    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
    //            this, SLOT(scrollTo(int)));
    connect (ui->btHelp, SIGNAL(clicked()), this, SLOT(scrollToHelpMenu()));
    connect (ui->btPlay, SIGNAL(clicked()), this, SLOT(scrollToPlayMenu()));

    //    grabKeyboard(); // dangerous! it take up all keyboard even alt f4!
}

GameMenu::~GameMenu()
{
    delete ui;
}

void GameMenu::keyPressEvent(QKeyEvent *ev)
{
    static int currentFrame = 1;
    QPushButton* button = qobject_cast<QPushButton*>(focusWidget());
    switch (ev->key()){
    case Qt::Key_Return:
    case Qt::Key_Enter:

        if (  button ){
            button->click();
            button->clearFocus();
        }
        break;
    case Qt::Key_Up:
    case Qt::Key_Down:
        if (!focusNextChild())
            focusPreviousChild();
        highlight(focusWidget());
        break;
    case Qt::Key_Left:
        currentFrame -= 1;
        scrollTo(currentFrame);
        break;
    case Qt::Key_Right:
        currentFrame += 1;
        scrollTo(currentFrame);
        break;
    default:
        break;
    }

//    buttonClickPlayer->play();
    QWidget::keyPressEvent(ev);
}

void GameMenu::showEvent(QShowEvent *ev)
{
    if (backgroundMusicPlayer) backgroundMusicPlayer->play();
    QWidget::showEvent(ev);
}

void GameMenu::closeEvent(QCloseEvent *ev)
{
    if (backgroundMusicPlayer) backgroundMusicPlayer->stop();
    return QWidget::closeEvent(ev);
}

void GameMenu::hideEvent(QHideEvent *ev)
{
   if (backgroundMusicPlayer) backgroundMusicPlayer->stop();
    return QWidget::hideEvent(ev);
}

void GameMenu::scrollTo(int frameIndex)
{
    if (frameIndex < 0 || frameIndex > 3) return;
    int new_x = frameIndex;
    int diff;
    int speed = ui->f_main->width();


    ui->description->hide();
    ui->highlighter->hide();
//    qDebug() << QString("scrolling to %1").arg(frameIndex);

    foreach (QFrame* frame, frames){
        diff  = (currentFrameIndex - new_x);

        sliding = new QPropertyAnimation(frame, "pos", this);

        sliding->setStartValue(frame->pos());
        sliding->setEndValue( QPoint(frame->x()+ (diff*speed), frame->y()) );
        sliding->setDuration(1000);
        sliding->setEasingCurve(QEasingCurve::InBack);
        sliding->start(QAbstractAnimation::DeleteWhenStopped);

    }

    currentFrameIndex = frameIndex;
    setChoicesFor(currentFrameIndex);

    QTimer::singleShot(1000, ui->description, SLOT(show()));
    QTimer::singleShot(1000, ui->highlighter, SLOT(show()));

//    qDebug() << QString("scrolled to %1").arg(currentFrameIndex);
}

void GameMenu::scrollToHelpMenu()
{
    scrollTo(0);
}

void GameMenu::scrollToPlayMenu()
{
    scrollTo(2);
}

void GameMenu::highlight(QWidget* target)
{
    ui->highlighter->move(target->pos()
//                          -QPoint(
//                              target->width(),
//                              target->height())/2
                          );
    describe(target->objectName());

    target->setFocus();
//    qDebug() << "focus widget: " << focusWidget();

    buttonClickPlayer->play();
}

void GameMenu::handleRemoteButtonPress(QByteArray data)
{
    // ABCD
    if (data == "A"){
        switch (currentFrameIndex) {
        case 1:
            qobject_cast<QPushButton*>( focusWidget() )->click();
            break;
        case 2:
            setPlayer();
            scrollTo( currentFrameIndex + 1 );
            break;
        case 3:
            setVenue();
            break;
        default:
            break;
        }
    }
    if (data == "B"){
        switch (currentFrameIndex) {
        case 0:
            scrollTo(1);
            break;
        case 2:
        case 3:
            scrollTo( currentFrameIndex - 1);
            break;
        default:
            break;
        }
    }
    if (data == "C"){
        switch (currentFrameIndex) {
        case 2:
        case 3:
            _configuration.clear();
            scrollTo(1);
            qDebug() << _configuration;
            break;
        default:
            break;
        }
    }
    if (data == "D"){
        switch (currentFrameIndex) {
        case 1:
            close();
            break;
        case 3:
            // hide this menu and launch the game
            qDebug() << "launching the game with following configuration:";
            qDebug() << _configuration;
            emit newGame(_configuration);
            break;
        default:
            break;
        }
    }

    // DIRECTION
    if (data == "_U"){
        if ( choices.isEmpty() ) return;
        if ( iterator != choices.begin() ){
            iterator--;
            highlight( *iterator );
        }

    }
    if (data == "_D"){
        if ( choices.isEmpty() ) return;
        if ( iterator != choices.end()-1 ){
            iterator++;
            highlight( *iterator );
        }
    }
    if (data == "_R"){
    }
    if (data == "_L"){
    }

    buttonClickPlayer->play();
}

void GameMenu::setPlayer()
{
    int playerNumber = focusWidget()->objectName()=="ash1"?1:2;
    _configuration.insert("player", playerNumber);
}

void GameMenu::setVenue()
{
    int venueNumber =
            focusWidget()->objectName()=="place1"?1
              :focusWidget()->objectName()=="place2"?2
                                                   :3;
    _configuration.insert("venue", venueNumber);

}

void GameMenu::replayBgMusic(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia){
        backgroundMusicPlayer->play();
    }
}

void GameMenu::adjustFrames()
{
    // some necessary variables
    QDesktopWidget* desktop = QApplication::desktop();
    int D_width = desktop->width();
    int D_height = desktop->height();

    frames.append(ui->f_help);
    frames.append(ui->f_main);
    frames.append(ui->f_player);
    frames.append(ui->f_venue);

    // adjusting all frames size
    this->resize(D_width, D_height);
    int margin = 10;
    int new_x = margin;
    foreach (QFrame* frame, frames){
        frame->resize(this->size()-QSize(margin, margin));
        frame->move(new_x, margin);
        new_x += frame->width() + margin;
    }

    // adjusting button size aspect ratio
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    int b_width = ui->f_main->width()/5;
    int b_height = ui->f_main->height()/5;
    foreach (QPushButton* button, buttons){
        button->setFixedSize(b_width, b_height);
    }

    // frames labels positioning
//    QList<QLabel*> labels = findChildren<QLabel*>();
//    foreach (QLabel* label, labels){
//        label->move(label->parentWidget()->width()-label->width(), 0);
//    }

    // individual frame setup
//    ui->helpText->resize(
//                0.50*ui->f_help->width(),
//                0.95*ui->f_help->height()
//                );
//    ui->helpText->move(
//                ui->f_help->width()/7,
//                15
//                );


    // [1] main menu
    ui->btHelp->move(
//                ui->f_main->width()/5,
                50,
                ui->f_main->height()/3
                );
    ui->btPlay->move(
//                ui->f_main->width()/5,
                50,
                (ui->f_main->height()/3)*2
                );
    ui->highlighter->resize(ui->btPlay->size()*1.5);

    // [2] select player
    ui->ash1->resize(b_width, b_height);
    ui->ash2->resize(b_width, b_height);

    ui->ash1->move(
//                ui->f_player->width()/5,
                50,
                ui->f_player->height()/3
                   );

    ui->ash2->move(
//                ui->f_player->width()/5,
                50,
                ui->f_player->height()/3*2
                   );

//    highlight(ui->ash2);

    // [3] select venue
    ui->place1->resize(b_width, b_height);
    ui->place2->resize(ui->place1->size());
    ui->place3->resize(ui->place1->size());


    ui->place1->move(
//                ui->f_venue->width()/5,
                50,
                ui->f_venue->height()/3*0.25
                );
    ui->place2->move(
//                ui->f_venue->width()/5,
                50,
                ui->f_venue->height()/3*1.25
                );
    ui->place3->move(
//                ui->f_venue->width()/5,
                50,
                ui->f_venue->height()/3*2.25
                );

//    ui->instruction->move(
//                ui->f_main->width()-ui->instruction->width(),
//                ui->f_main->height()-ui->instruction->height()
//                );
    ui->description->move(
                ui->f_main->width()/3*2,
                ui->f_main->height()/2 - ui->description->height()
                );

    // finally
    scrollTo(1);
    highlight(ui->btHelp);
}

void GameMenu::setChoicesFor(int frameIndex)
{
    choices.clear();
    QString instruction;

    switch (frameIndex) {
    case 0:
        ui->description->setText("Help Page");
        choices.clear();
        instruction = "[ b ] back";
        break;
    case 1:
        choices << ui->btHelp << ui->btPlay;
        instruction = "[ a ] select\n[ d ] quit game";
        break;
    case 2:
        choices << ui->ash1 << ui->ash2;
        instruction = "[ a ] accept\n[ b ] back\n[ c ] cancel";
        break;
    case 3:
        choices << ui->place1 << ui->place2 << ui->place3;
        instruction =
                "[ a ] accept\n[ b ] back\n[ c ] cancel\n"
                "[ d ] start game";
    default:
        break;
    }


    if (!choices.isEmpty()){
    iterator = choices.begin();
    highlight( *iterator );

    }
//    ui->instruction->setText(instruction);

//    nit = 0;
//    highlight(  choices.at(nit) );


}

void GameMenu::describe(const QString &targetName)
{
    QString description = "";

    if (targetName == "btHelp")
        description = "Press to get help";
    if (targetName == "btPlay")
        description = "Press to play";

    if (targetName == "ash1")
        description = "the RED ASH";
    if (targetName == "ash2")
        description = "the BLUE ASH";

    if (targetName == "place1")
        description = "Byte Beach";
    if (targetName == "place2")
        description = "Outer Space";
    if (targetName == "place3")
        description = "Night City";

    return ui->description->setText(description);;
}
