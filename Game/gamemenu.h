#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QFrame>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class GameMenu;
}

class GameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = 0);
    ~GameMenu();

signals:
    void newGame(QMap<QString, int> configuration);

protected:
    void keyPressEvent(QKeyEvent *);
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
    void hideEvent(QHideEvent *);

public slots:
    void scrollTo(int frameIndex);
    void highlight(QWidget *target);

    void scrollToHelpMenu();
    void scrollToPlayMenu();

    void handleRemoteButtonPress(QByteArray data);

    void setPlayer();
    void setVenue();

    void replayBgMusic(QMediaPlayer::MediaStatus);

private:
    void adjustFrames();
    void setChoicesFor(int frameIndex);
    void describe(const QString& targetName);

private:
    Ui::GameMenu *ui;
    QList<QFrame*> frames;
    QPropertyAnimation* sliding;

    int currentFrameIndex;
    QList<QPushButton*> choices;
    QList<QPushButton*>::iterator iterator; //bug!, I'll report
                                            // no it is not
                                            // it is you the bug one
    QMap<QString, int> _configuration;


    // soundfx and music stuff
    QMediaPlayer* backgroundMusicPlayer;
    QMediaPlayer* buttonClickPlayer;
};

#endif // GAMEMENU_H
