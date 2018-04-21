#ifndef DARKSHIELD_H
#define DARKSHIELD_H

#include <QLabel>
#include <QWidget>

class DarkShield : public QWidget
{
    Q_OBJECT
public:
    explicit DarkShield(QWidget *parent = 0);

    void setTitle(const QString title);
    void setInfo(const QString info);

    void keyPressEvent(QKeyEvent *ev);

signals:
    void a_pressed();
    void b_pressed();
    void c_pressed();
    void d_pressed();

    void appeared();
    void disappeared();


public slots:
    void surprise();
    void disappear();

private:
    QLabel* titleFace;
    QLabel* infoFace;
    QString _title;
    QString _info;
};

#endif // DARKSHIELD_H
