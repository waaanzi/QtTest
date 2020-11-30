#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

QPushButton* button = new QPushButton(this);
button->setText(QString::number(111));
button->move(10, 40);
button->setObjectName(QStringLiteral("btn"));
qDebug() << button->objectName();
QMetaObject::connectSlotsByName(this);

    ui->setupUi(this);


       //bool b = connect(button, SIGNAL(clicked(bool)), this, SLOT(btn_clicked1111()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
 qDebug() << "on_pushButton_clicked ";
}

void MainWindow::on_pushButton1_clicked()
{

}

void MainWindow::on_btn_clicked()
{
    //MyBtn * btn = qobject_cast<MyBtn*>(sender());
    qDebug() << "on_btn_sig: " ;
}

