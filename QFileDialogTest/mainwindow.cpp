#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QProgressDialog>
#include <QDir>
#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pDlg(NULL)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QDir dir("C:\\Users\\zhangli01\\Documents\\xinge\\plugins\\73f3d7817d1b4302a6b4f11fab0217ec");
    if (dir.exists())
    {
    QStringList list = dir.entryList(QDir::Dirs | QDir ::Files | QDir::NoDotAndDotDot);

    qDebug() << list;
    }

    return;

    QWidget *pWidget = new QWidget();
//    delete pWidget;
    QString ss = QFileDialog::getSaveFileName(pWidget,
                                              QString("saveAs"),
                                              QString("鈥狢:\\Users\\zhangli01\\Desktop\\123\\1.txt"),
                                              QObject::tr(";;All Files (*.*)"));
}

void MainWindow::on_progressBtn_clicked()
{
    if (NULL == m_pDlg)
    {
    m_pDlg = new QProgressDialog(QObject::tr("正在下载"), QObject::tr("关闭"),
                                 1, 100);
    m_pDlg->setWindowTitle(QObject::tr("友情提示"));
    m_pDlg->setWindowModality(Qt::WindowModal);
    m_pDlg->setFixedSize(300, 200);
    m_pDlg->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    }
    if(m_pDlg->isHidden())
    {
        int i;
        i++;
    }
    m_pDlg->show();

    connect(m_pDlg, SIGNAL(canceled()), this, SLOT(slotProgressDlg()));
}

void MainWindow::slotProgressDlg()
{
  int i = 0;
  i++;
}
