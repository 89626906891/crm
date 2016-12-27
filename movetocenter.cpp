#include "movetocenter.h"

//отцентровка окна
void moveToCenter(QWidget& widget)
{
    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen());
    QPoint center = rect.center(); //координаты центра экрана
    center.setX(center.x() - (widget.width()/2));
    center.setY(center.y() - (widget.height()/2));
    widget.move(center);
}
//отцентровка с использованием перегрузки функции
void moveToCenter(QWidget* widget)
{
    moveToCenter(*widget);
}
