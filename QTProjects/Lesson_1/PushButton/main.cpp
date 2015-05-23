#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton *pb = new QPushButton("close");
    pb->show();
    return a.exec();
}
