#ifndef DIGITENLAUNCHER_H
#define DIGITENLAUNCHER_H

#include <QWidget>

namespace Ui {
class DigitenLauncher;
}

class DigitenLauncher : public QWidget
{
    Q_OBJECT

public:
    explicit DigitenLauncher(QWidget *parent = 0);
    ~DigitenLauncher();

private:
    Ui::DigitenLauncher *ui;
};

#endif // DIGITENLAUNCHER_H
