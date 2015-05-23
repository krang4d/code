#include "dialog.h"

myDialog::myDialog(QWidget *parent) : QDialog(parent)
{
    lbl = new QLabel("&Ввод");
    line = new QLineEdit;
    lbl->setBuddy(line);

    cb1 = new QCheckBox("Верхни регистор");
    cb2 = new QCheckBox("Инверсия");

    ok = new QPushButton("Ok");
    ok->setDefault(true);
    ok->setEnabled(false);
    close = new QPushButton("Выход");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(lbl);
    layout->addWidget(line);

    QVBoxLayout *right = new QVBoxLayout;
    right->addLayout(layout);
    right->addWidget(cb1);
    right->addWidget(cb2);

    QVBoxLayout *left = new QVBoxLayout;
    left->addWidget(ok);
    left->addWidget(close);

    QHBoxLayout *main  = new QHBoxLayout;
    main->addLayout(right);
    main->addLayout(left);

    connect(line,SIGNAL(textChanged(QString)), this,SLOT(TextChanged(QString)));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkClicked()));

    setLayout(main);
    setWindowTitle("MassageBox");
}

myDialog::~myDialog()
{

}

void myDialog::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());

}

void myDialog::OkClicked()
{
    if (!cb1->isChecked() && !cb2->isChecked())
        emit Simple(line->text());
    if (cb1->isChecked() && cb2->isChecked())
        emit RegisterAndInvers(line->text());
    else if (cb1->isChecked())
        emit Register(line->text());
    else if (cb2->isChecked())
        emit Invers(line->text());
}
