#include <QApplication>
//#include "ui_mydialogwindow.h"
#include "mydialogwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    Ui_MyDialogWindow *b = new Ui_MyDialogWindow();
    QDialog *wnd = new QDialog();

    b->setupUi(wnd);
    wnd->show();
    */
    MyDialogWindow *wnd = new MyDialogWindow();
    wnd->show();

    return a.exec();
}
