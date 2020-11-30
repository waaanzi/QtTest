#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QStyledItemDelegate>
#include <QLabel>

class MyTreeDelegate : public QStyledItemDelegate
{
public:
    MyTreeDelegate(QObject* parent, QLabel* label);
    ~MyTreeDelegate(){}

protected:
    void paint(QPainter* painter,
               const QStyleOptionViewItem& option,
               const QModelIndex& index) const;
private:
    QLabel* label_;
};




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
