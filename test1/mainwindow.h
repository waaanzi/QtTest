#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MyBtn : public QPushButton
{
Q_OBJECT
public:
    explicit MyBtn(QWidget *parent = Q_NULLPTR) : QPushButton(parent){};

signals:
    void sig(int,int,int);
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

private slots:
    void on_pushButton_clicked();
    void on_pushButton1_clicked();

    void on_btn_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
