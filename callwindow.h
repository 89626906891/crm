#ifndef CALLWINDOW_H
#define CALLWINDOW_H

#include <QWidget>

namespace Ui {
class CallWindow;
}

class CallWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CallWindow(QWidget *parent = 0);
    ~CallWindow();

private slots:
    void on_answerPushButton_clicked();
signals:
    void answer();

private:
    Ui::CallWindow *ui;
};

#endif // CALLWINDOW_H
