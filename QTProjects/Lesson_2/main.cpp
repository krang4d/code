#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myDialog *dialog = new myDialog;
    dialog->show();

    str *n = new str;

    QObject::connect(dialog,SIGNAL(Simple(QString)),n,SLOT(Simple(QString)));
    QObject::connect(dialog,SIGNAL(Invers(QString)),n,SLOT(Inversia(QString)));
    QObject::connect(dialog,SIGNAL(Register(QString)),n,SLOT(Register(QString)));
    QObject::connect(dialog,SIGNAL(RegisterAndInvers(QString)),n,SLOT(All(QString)));
    return a.exec();
}
