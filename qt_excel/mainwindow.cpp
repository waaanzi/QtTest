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
    // ui->label->setText(QObject::tr("竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界竞技世界"));
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
    excel->dynamicCall("SetVisible (bool Visible)","false"); // 不显示窗体
    excel->setProperty("DisplayAlerts", false); // 不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示


    // 工作簿
    QAxObject *workbooks = excel->querySubObject("WorkBooks"); // 获取工作簿集合
    QAxObject *workbook = NULL;
    QFile file(fileName);
    if (file.exists())
    {
        workbook = workbooks->querySubObject("Open(const QString &)", fileName);
    }
    else
    {
        workbooks->dynamicCall("Add"); // 新建一个工作簿
        workbook = excel->querySubObject("ActiveWorkBook"); // 获取当前工作簿
    }




    QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

    QAxObject *cell;
    // 标题行
    cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
    cell->dynamicCall("SetValue(const QString&)", "title");
    cell->querySubObject("Font")->setProperty("Size", 18);
    // 合并
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
    merge_range->setProperty("MergeCells", true);  //合并单元格



    //调整行高
    worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);


    // 列标题
    QStringList cNames;
    cNames << QString::fromLocal8Bit("序号")
           << QString::fromLocal8Bit("文章名称")
           << QString::fromLocal8Bit("文章推送时间")
           << QString::fromLocal8Bit("姓名" )
           << QString::fromLocal8Bit("部门")
           << QString::fromLocal8Bit("是否阅读")
           << QString::fromLocal8Bit("阅读时间");

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

    // 数据，第3行开始
    for(int i=0;i<cNames.size();i++)
    {
        cell=worksheet->querySubObject("Cells(int,int)", 3, i+1);
        cell->dynamicCall("SetValue(const QString&)", "test\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest\r\ntest");
        cell->setProperty("WrapText", true);
    }



    // 保存
    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName)); // 保存至fileName
    workbook->dynamicCall("Close()"); // 关闭工作簿
    excel->dynamicCall("Quit()"); // 关闭excel
    delete excel;
    excel=NULL;

    if (QMessageBox::question(NULL, QString::fromLocal8Bit("完成"),
                              QString::fromLocal8Bit("文件已经导出，是否现在打开？"),
                              QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
    }
}
