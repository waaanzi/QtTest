#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QDateTime>
#include <QMainWindow>
#include <inttypes.h>

const uint64_t kTimelineBaseRef = uint64_t(17863) * 24 * 60 * 60 * 1000;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("Link系统开发转换工具V1.0"));
    ui->tip1->setStyleSheet("font: bold 14px;");
    ui->tip2->setStyleSheet("font: bold 14px;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    uint64_t timeline = ui->textEdit_tl->toPlainText().toULongLong();
    uint64_t timestamp =( ( timeline << 1 ) >> 23 ) + kTimelineBaseRef;
    ui->textEdit_ts->setText(QString::number(timestamp));
    QDateTime t = QDateTime::fromMSecsSinceEpoch(timestamp);
    ui->textEdit_t->setText(t.toString("yyyy-MM-dd-hh-MM-ss-zzz"));
}

void MainWindow::on_pushButton_2_clicked()
{
}

void MainWindow::on_pushButton_link2product_clicked()
{
    uint64_t linkid = ui->textEdit_linkid->toPlainText().trimmed().toULongLong();
    uint32_t appid = linkid >> 44;
    uint32_t productid_type = (linkid << 20) >> 60;
    uint32_t productid = (linkid << 24) >> 24;

    ui->textEdit_appid->setText(QString::number(appid));
    ui->textEdit_productidtype->setText(QString::number(productid_type));
    ui->textEdit_productid->setText(QString::number(productid));
}

void MainWindow::on_pushButton_product2link_clicked()
{
    uint32_t appid = ui->textEdit_appid->toPlainText().toULong();
    uint32_t productid_type = ui->textEdit_productidtype->toPlainText().toULong();
    uint32_t productid = ui->textEdit_productid->toPlainText().toULongLong();

    uint64_t linkid = 0;
      linkid |= (uint64_t(appid) << 44);
      linkid |= (uint64_t(productid_type) << 40);
      linkid |= productid;

    ui->textEdit_linkid->setText(QString::number(linkid));
}
