#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QProgressDialog;

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
    void on_progressBtn_clicked();

    void slotProgressDlg();

private:
    Ui::MainWindow *ui;
    QProgressDialog *m_pDlg;
};

#endif // MAINWINDOW_H
