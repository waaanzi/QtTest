#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

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
void slotTextChanged();
void slotTest();
void slotMenuClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QListWidget* m_atmenu;
    QStringList m_list;
    QString m_attarget;
};

#endif // MAINWINDOW_H
