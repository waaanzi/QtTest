#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHideEvent>
#include <QFileInfo>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFileInfo info("C:\\Users\\zhangli01\\Documents\\xinge\\12121111111");//13099999999
    if (info.exists())
    {
        if (info.isSymLink())
        {
            int i =0;
            i++;
        }
        if (info.isDir())
        {
            int i =0;
            i++;
        }
    }

    QDir dir("C:\\Users\\zhangli01\\Documents\\xinge\\13099999999");
    if (dir.exists())
    {
        if (dir.entryInfoList().isEmpty())
        {
            int i =0;
            i++;
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideEvent(QHideEvent *event)
{
    QEvent::Type tt = event->type();
    QMainWindow::hideEvent(event);
}

void MainWindow::showEvent(QShowEvent *event)
{
    QEvent::Type tt = event->type();
    QMainWindow::showEvent(event);
}

bool MainWindow::event(QEvent *event)
{
    QEvent::Type tt = event->type();
    if (QEvent::Show == tt || QEvent::Hide == tt)
    {
        int i =0;
        i++;
    }
    return QMainWindow::event(event);
}
