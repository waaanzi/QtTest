#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAxObject>
#include <QFileDialog>
#include <QFile>
#include <QStandardPaths>
#include <QString>
#include <QDesktopServices>
#include <QDir>
#include <QObject>
#include <QUrl>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // ui->label->setWordWrap(true);
    // ui->label->setText(QObject::tr("�������羺�����羺�����羺�����羺�����羺�����羺�����羺�����羺�����羺�����羺�����羺������"));
    // ui->label->setText("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
    //                    "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
    //                    "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
    //                    "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    ui->textEdit->setEnabled(false);
    ui->textEdit->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    ui->textEdit->setText("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
                          "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
                          "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
                          "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");

    return;

    QString fileName = QFileDialog::getSaveFileName(NULL, "export",
                                                    QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),
                                                    "Excel files(*.xls *.xlsx)");
    if(fileName.isEmpty())
    {
      return;
    }


    QAxObject *excel = new QAxObject;
    excel->setControl("Excel.Application");
    excel->dynamicCall("SetVisible (bool Visible)","false"); // ����ʾ����
    excel->setProperty("DisplayAlerts", false); // ����ʾ�κξ�����Ϣ�����Ϊtrue��ô�ڹر��ǻ�������ơ��ļ����޸ģ��Ƿ񱣴桱����ʾ


    // ������
    QAxObject *workbooks = excel->querySubObject("WorkBooks"); // ��ȡ����������
    QAxObject *workbook = NULL;
    QFile file(fileName);
    if (file.exists())
    {
        workbook = workbooks->querySubObject("Open(const QString &)", fileName);
    }
    else
    {
        workbooks->dynamicCall("Add"); // �½�һ��������
        workbook = excel->querySubObject("ActiveWorkBook"); // ��ȡ��ǰ������
    }




    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

    QAxObject *cell;
    // ������
    cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
    cell->dynamicCall("SetValue(const QString&)", "title");
    cell->querySubObject("Font")->setProperty("Size", 18);
    // �ϲ�
    QString merge_cell;
    merge_cell.append(QChar('A'));
    merge_cell.append(QString::number(1));
    merge_cell.append(":");
    merge_cell.append(QChar(6+ 'A'));
    merge_cell.append(QString::number(1));
    QAxObject *merge_range = worksheet->querySubObject("Range(const QString&)", merge_cell);
    merge_range->setProperty("HorizontalAlignment", -4108);
    merge_range->setProperty("VerticalAlignment", -4108);
    merge_range->setProperty("WrapText", true);
    merge_range->setProperty("MergeCells", true);  //�ϲ���Ԫ��



    //�����и�
    worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);


    // �б���
    QStringList cNames;
    cNames << QString::fromLocal8Bit("���")
           << QString::fromLocal8Bit("��������")
           << QString::fromLocal8Bit("��������ʱ��")
           << QString::fromLocal8Bit("����" )
           << QString::fromLocal8Bit("����")
           << QString::fromLocal8Bit("�Ƿ��Ķ�")
           << QString::fromLocal8Bit("�Ķ�ʱ��");

    for(int i=0;i<cNames.size();i++)
    {
        QString columnName;
        columnName.append(QChar(i  + 'A'));
        columnName.append(":");
        columnName.append(QChar(i + 'A'));
        QAxObject* col = worksheet->querySubObject("Columns(const QString&)", columnName);
        col->setProperty("ColumnWidth", 20);
        cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
        columnName=cNames[i];
        cell->dynamicCall("SetValue(const QString&)", columnName);
        cell->querySubObject("Font")->setProperty("Bold", true);
        cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
        cell->setProperty("HorizontalAlignment", -4108); // xlCenter
        cell->setProperty("VerticalAlignment", -4108); // xlCenter
    }

    // ���ݣ���3�п�ʼ
    for(int i=0;i<cNames.size();i++)
    {
        cell=worksheet->querySubObject("Cells(int,int)", 3, i+1);
        cell->dynamicCall("SetValue(const QString&)", "test\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest");
        cell->setProperty("WrapText", true);
    }



    // ����
    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName)); // ������fileName
    workbook->dynamicCall("Close()"); // �رչ�����
    excel->dynamicCall("Quit()"); // �ر�excel
    delete excel;
    excel=NULL;

    if (QMessageBox::question(NULL, QString::fromLocal8Bit("���"),
                              QString::fromLocal8Bit("�ļ��Ѿ��������Ƿ����ڴ򿪣�"),
                              QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
    }
}
