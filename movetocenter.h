#ifndef MOVETOCENTER_H
#define MOVETOCENTER_H

#include <QObject>
#include <QWidget>
#include <QRect>
#include <QPoint>
#include <QDesktopWidget>


   void  moveToCenter(QWidget& widget); //перегрузка функций
   void  moveToCenter(QWidget* widget);//отцентровка открывающихся окон

#endif // MOVETOCENTER_H
