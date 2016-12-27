#include "buttondelegate.h"

buttonDelegate::buttonDelegate(QObject *parent):QItemDelegate(parent)
{

}
//отрисовка кнопки
void buttonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionButton button;
    QRect r = option.rect;//getting the rect of the cell
    int x,y,w,h;
    x = r.left() + r.width() - 30;//the X coordinate
    y = r.top();//the Y coordinate
    w = 30;//ширина кнопки
    h = 30;//высота кнопки
    button.rect = QRect(x,y,w,h);
    button.text = "=^.^=";
    button.state = QStyle::State_Enabled;

    QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
}
//отслеживаем клик по кнопке
bool buttonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if( event->type() == QEvent::MouseButtonRelease )
    {
        QMouseEvent * e = (QMouseEvent *)event;
        int clickX = e->x();
        int clickY = e->y();

        QRect r = option.rect;//getting the rect of the cell
        int x,y,w,h;
        x = r.left() + r.width() - 30;//the X coordinate
        y = r.top();//the Y coordinate
        w = 30;//ширина кнопки
        h = 30;//высота кнопки

        //если попали в кнопку
        if( clickX > x && clickX < x + w )
            if( clickY > y && clickY < y + h )
            {
                qDebug() << index.column();
                qDebug() << index.row();
                QDialog * d = new QDialog();
                d->setGeometry(0,0,100,100);
                d->show();
            }
    }
}
