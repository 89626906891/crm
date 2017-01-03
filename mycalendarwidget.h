#ifndef MYCALENDARWIDGET_H
#define MYCALENDARWIDGET_H
#include <QCalendarWidget>
#include <QColor>
#include <QDate>
#include <QPen>
#include <QBrush>
#include <QPainter>

class myCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

   // Q_PROPERTY(QColor color READ getColor WRITE setColor)
public:
    explicit myCalendarWidget(QWidget *parent = 0);
    ~myCalendarWidget();

    void setColor(QColor& color);
    QColor getColor();

private:
   QDate m_currentDate;
   QPen m_outlinePen;
   QBrush m_transparentBrush;


signals:

public slots:

    // QCalendarWidget interface
protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;
};

#endif // MYCALENDARWIDGET_H
