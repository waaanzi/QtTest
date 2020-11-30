#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->in->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    ui->in->setAcceptRichText(true);
    connect(ui->in, SIGNAL(textChanged()), this, SLOT(slotShowText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShowText()
{
    ui->out->setText(ui->in->toPlainText());
}
