#include "centering.h"
QPoint center_point(const QWidget *widget)
{
    QDesktopWidget desktop;
    int x = (desktop.width() - widget->width()) / 2;
    int y = (desktop.height() - widget->height()) /2;
    return QPoint(x, y);
}
