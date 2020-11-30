#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextBlock>
#include <QTextCharFormat>
#include <iostream>
#include <QPoint>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_atmenu = new QListWidget(this);
    m_atmenu->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    m_atmenu->setAttribute(Qt::WA_TranslucentBackground);

    m_list << "1111111" << "2222" << "33" << QString::fromLocal8Bit("中兴") << QString::fromLocal8Bit("华为")
           << QString::fromLocal8Bit("信鸽") << "61" << "62" << "63";
    m_atmenu->addItems(m_list);
    m_atmenu->setMaximumWidth(100);
    m_atmenu->setMaximumHeight(150);
    m_atmenu->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    m_atmenu->hide();

    connect(m_atmenu, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(slotMenuClicked(QListWidgetItem *)));

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(slotTextChanged()));
    connect(ui->textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(slotTest()));
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_atmenu){
        delete m_atmenu;
    }
}

void MainWindow::slotTextChanged()
{
    // std::cout << this->toPlainText().toStdString() << std::endl;
}

void MainWindow::slotTest()
{
    m_atmenu->hide();
    m_attarget = "";

    QTextCursor c = ui->textEdit->textCursor();

    // 光标在结尾
    if (!c.atEnd())
    {
      return;
    }

    QTextBlock block = c.block();
    if (!block.isValid())
    {
        return;
    }

    // 排除textedit 内容为空的场景
    QTextBlock::iterator it = block.end();
    if (it == block.begin() )
    {
      return;
    }

    // block与fragment关系
    qDebug() << "block text: ";
    QString text;
    for(auto it = block.begin(); it != block.end();it++)
    {
        QTextFragment fragment = it.fragment();
        QTextCharFormat charFmt = fragment.charFormat();

        if (!charFmt.isImageFormat())
        {
            qDebug() << fragment.text();
            text +=fragment.text();
        }
        else
        {
           text = "";
        }
    }
    qDebug() << "\n";

    // // 取最后一个fragment
    // it--;
    // QTextFragment fragment = it.fragment();
    // int len = fragment.length();
    // QTextCharFormat charFmt = fragment.charFormat();
    //
    // // 只找纯文本
    // if (!charFmt.isImageFormat())
    // {
    //   qDebug() << "fragment.text(): " << fragment.text() << "\n";
    //   QString text = fragment.text();
      int pos = text.lastIndexOf('@');
      if (!text.isEmpty() && (-1 != pos))
      {
        QString target = text.mid(pos + 1);
        int originlen = target.length();
        target = target.trimmed();
        if (originlen - target.length() > 2)
        {
            // 即首尾带2个以上空格，直接返回
            return;
        }

        QStringList temp;
        bool find = false;
        int index = 0;
        for (QString item : m_list)
        {
            m_atmenu->item(index)->setHidden(true);
           if (item.startsWith(target))
           {
               temp << item;
               find = true;
               m_atmenu->item(index)->setHidden(false);
           }
           ++index;
        }

        if (!find)
        {
           return;
        }

        m_attarget = target;

        qDebug() << "target: " << target << "\n";
        auto x = ui->textEdit->cursorRect().x();
        auto y = ui->textEdit->cursorRect().y();
        // std::cout << "cursorRect x: " << x << " y: " << y << std::endl;

        // pos相对于parent
        auto p = mapToParent(QPoint(x + 2, y + 24) + ui->textEdit->pos());
        // std::cout << "mapToParent x: " << p.x() << " y: " << p.y() << std::endl;
        // p = mapToGlobal(QPoint(x, y));
        // std::cout << "mapToGlobal x: " << p.x() << " y: " << p.y() << std::endl;
        // p = mapFromGlobal(QPoint(x, y));
        // std::cout << "mapFromGlobal x: " << p.x() << " y: " << p.y() << std::endl;
        // p = mapFromParent(QPoint(x, y));
        // std::cout << "mapFromParent x: " << p.x() << " y: " << p.y() << std::endl;


        m_atmenu->move(p);
        m_atmenu->resize(m_atmenu->width(),  21 * temp.size());
        m_atmenu->setFocusPolicy(Qt::ClickFocus);
        m_atmenu->showNormal();
        m_atmenu->setWindowState(Qt::WindowNoState);
        m_atmenu->clearFocus();
        ui->textEdit->show();
        ui->textEdit->activateWindow();
      }
   // }

}

void MainWindow::slotMenuClicked(QListWidgetItem *item)
{
    QTextCursor c = ui->textEdit->textCursor();
    if (!m_attarget.isEmpty())
    {
       c.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor, m_attarget.size());
       c.deleteChar();
    }
    QString text = item->text();
    c.insertText(text);
    m_atmenu->hide();

}
