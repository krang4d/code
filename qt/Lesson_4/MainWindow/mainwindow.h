#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QGridLayout>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>

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
private slots:
    void action()
    {
        QMessageBox *msg = new QMessageBox();
        msg->setText("Action");
        msg->exec();
    }
    void on_actionNewWindow_triggered();
    void on_actionClose_triggered();
};

#endif // MAINWINDOW_H
