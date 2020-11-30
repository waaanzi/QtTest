#include "widget.h"
#include "ui_widget.h"
#include <QKeySequence>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    lbl_ = new QLabel(this);
    lbl_->setFixedSize(200,50);

    QLabel *lbl2 = new QLabel(this);
    lbl2->setFixedSize(200,50);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(lbl_);
    layout->addWidget(lbl2);
    //QKeySequenceEdit *edit = new CustomKeySequenceEdit(this);
   // myEdit * edit = new myEdit;
    QPushButton * edit = new QPushButton;
    edit->setFixedSize(200,50);
    layout->addWidget(edit);
    edit->clearFocus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int shortcut = event->key();
//    if (!((shortcut >= Qt::Key_A) && (shortcut <= Qt::Key_Z)) &&
//      !((shortcut >= Qt::Key_0) && (shortcut <= Qt::Key_9)))
//    {
//        shortcut = 0;
//    }
     Qt::Key key = static_cast<Qt::Key>(shortcut);
//     if(key == Qt::Key_unknown)
//     {
//        shortcut = 0;
//     }
//     else
//     {
//         shortcut = key;
//     }
    Qt::KeyboardModifiers modifiers = event->modifiers();
    Qt::KeyboardModifiers all = Qt::ShiftModifier | Qt::ControlModifier | Qt::AltModifier | Qt::MetaModifier;
    if (modifiers & all)
    {
        shortcut += modifiers & all;
    }
//    if(modifiers & Qt::ControlModifier)
//    {
//        shortcut += Qt::CTRL;
//    }
//    else if(modifiers & Qt::AltModifier)
//    {
//        shortcut += Qt::ALT;
//    }
//    else if(modifiers & Qt::MetaModifier)
//    {
//        shortcut += Qt::META;
//    }
    qDebug() << "Widget::keyPressEvent" << QKeySequence(shortcut).toString(QKeySequence::NativeText);
    lbl_->setText(QKeySequence(shortcut).toString(QKeySequence::NativeText));
    QMessageBox::information(NULL, "Widget", QKeySequence(shortcut).toString(QKeySequence::NativeText));
    QWidget::keyPressEvent(event);
}

//CustomKeySequenceEdit::CustomKeySequenceEdit(QWidget *parent)
//    : QKeySequenceEdit(parent)
//{

//}

//void CustomKeySequenceEdit::keyPressEvent(QKeyEvent *pEvent)
//{
//    QKeySequenceEdit::keyPressEvent(pEvent);
//    QKeySequence seq(QKeySequence::fromString(keySequence().toString().split(", ").first()));
//    setKeySequence(seq);
//}

void myEdit::keyPressEvent(QKeyEvent *event)
{
    int shortcut = event->key();
//    if (!((shortcut >= Qt::Key_A) && (shortcut <= Qt::Key_Z)) &&
//      !((shortcut >= Qt::Key_0) && (shortcut <= Qt::Key_9)))
//    {
//        shortcut = 0;
//    }
     Qt::Key key = static_cast<Qt::Key>(shortcut);
//     if(key == Qt::Key_unknown)
//     {
//        shortcut = 0;
//     }
//     else
//     {
//         shortcut = key;
//     }
    Qt::KeyboardModifiers modifiers = event->modifiers();
    Qt::KeyboardModifiers all = Qt::ShiftModifier | Qt::ControlModifier | Qt::AltModifier | Qt::MetaModifier;
    if (modifiers & all)
    {
        shortcut += modifiers & all;
    }
//    if(modifiers & Qt::ControlModifier)
//    {
//        shortcut += Qt::CTRL;
//    }
//    else if(modifiers & Qt::AltModifier)
//    {
//        shortcut += Qt::ALT;
//    }
//    else if(modifiers & Qt::MetaModifier)
//    {
//        shortcut += Qt::META;
//    }
    qDebug() << "myEdit::keyPressEvent" <<QKeySequence(shortcut).toString(QKeySequence::NativeText);
    QMessageBox::information(NULL, "myEdit", QKeySequence(shortcut).toString(QKeySequence::NativeText));
    QLineEdit::keyPressEvent(event);
}
