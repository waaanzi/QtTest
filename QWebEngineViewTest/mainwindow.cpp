#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView *view = new QWebEngineView(this);
    setCentralWidget(view);
    view->load(QUrl("http://www.baidu.com/"));
    view->setContextMenuPolicy(Qt::DefaultContextMenu);
}


MainWindow::~MainWindow()
{
    delete ui;
}
