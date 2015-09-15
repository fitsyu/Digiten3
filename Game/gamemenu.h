#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>

namespace Ui {
class GameMenu;
}

class GameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = 0);
    ~GameMenu();

private:
    Ui::GameMenu *ui;
};

#endif // GAMEMENU_H
