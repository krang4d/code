#include "mydialogwindow.h"
#include "ui_mydialogwindow.h"

MyDialogWindow::MyDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialogWindow)
{
    ui->setupUi(this);
}

MyDialogWindow::~MyDialogWindow()
{
    delete ui;
}
