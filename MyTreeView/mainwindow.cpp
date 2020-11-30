#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <iostream>
#include <QPainter>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置delegate
    QTreeView* tree = ui->treeView;
    tree->setItemDelegate(new MyTreeDelegate(tree, ui->label));

    // 设置model
    QStandardItemModel *model = new QStandardItemModel(tree);
    model->setHorizontalHeaderLabels(QStringList()<< "Demo");
    model->appendRow(new QStandardItem("1"));
    model->item(0)->appendRow(new QStandardItem("11"));
    model->item(0)->appendRow(new QStandardItem("12"));
    model->item(0)->appendRow(new QStandardItem("13"));
    model->item(0)->appendRow(new QStandardItem("14"));
    model->item(0)->appendRow(new QStandardItem("15"));
    model->item(0)->appendRow(new QStandardItem("16"));
    model->item(0)->appendRow(new QStandardItem("17"));
    model->item(0)->appendRow(new QStandardItem("18"));
    model->item(0)->appendRow(new QStandardItem("19"));
    model->item(0)->appendRow(new QStandardItem("20"));
    model->appendRow(new QStandardItem("2"));
    model->appendRow(new QStandardItem("3"));
    model->appendRow(new QStandardItem("4"));
    model->appendRow(new QStandardItem("5"));
    model->appendRow(new QStandardItem("6"));
    model->appendRow(new QStandardItem("7"));
    tree->setModel(model);

    // 设置VerticalScrollBarPolicy
    tree->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MyTreeDelegate::MyTreeDelegate(QObject *parent, QLabel* label)
: QStyledItemDelegate(parent),label_(label)
{
}

void MyTreeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect rect = option.rect;
    QTreeView* tree = dynamic_cast<QTreeView*>(parent());
    if(NULL != tree->verticalScrollBar() && tree->verticalScrollBar()->isVisible())
    {
        label_->setText(QString("TreeView VerticalScrollBar visible, width:") +
                        QString::number(tree->verticalScrollBar()->width()));

        // 补偿宽度
        rect.setRight(rect.right() + tree->verticalScrollBar()->width());
    }
    else
    {
        label_->setText(QString("TreeView VerticalScrollBar is not visible!"));
     }

    rect.setRight(rect.right() - 20);
    painter->drawText(rect, Qt::AlignVCenter | Qt::AlignRight, QString("rect.right:") +
                      QString::number(rect.right()));
    QStyledItemDelegate::paint(painter, option, index);
}
