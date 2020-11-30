#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QKeySequenceEdit>
#include <QLineEdit>
//class CustomKeySequenceEdit : public QKeySequenceEdit
//{
//public:
//    explicit CustomKeySequenceEdit(QWidget *parent = 0);
//    ~CustomKeySequenceEdit(){};
//protected:
//    void keyPressEvent(QKeyEvent* pEvent);
//};

namespace Ui {
class Widget;
}

class myEdit : public QLineEdit
{

protected:
    void keyPressEvent(QKeyEvent *event);

};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    QLabel *lbl_;
};

#endif // WIDGET_H
