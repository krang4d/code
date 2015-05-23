#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl("Hello Pasha!");
    QSpinBox *pb = new QSpinBox();
    QSlider *sl = new QSlider(Qt::Horizontal);

    pb->setMaximum(100);
    sl->setMaximum(100);

    QWidget *window = new QWidget;
    QHBoxLayout *hlayout = new QHBoxLayout;

    hlayout->addWidget(pb);
    hlayout->addWidget(sl);
    hlayout->addWidget(&lbl);

    window->setLayout(hlayout);

    QObject::connect(sl,SIGNAL(valueChanged(int)),pb,SLOT(setValue(int)));
    QObject::connect(pb,SIGNAL(valueChanged(int)),sl,SLOT(setValue(int)));


    window->show();
    return a.exec();
}
