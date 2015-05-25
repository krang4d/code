#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionNewWindow->setIcon(QIcon(":/Images/girls.png"));
    //setCentralWidget(ui->textEdit);

   /*
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(ui->pushButton,0,1);
    grid->addWidget(ui->pushButton_2,1,0);

    QWidget *as = new QWidget(this);
    as->setLayout(grid);
    setCentralWidget(as);
   */
    QMenu *file = menuBar()->addMenu("File");
    //QMenu *Edit = menuBar()->addMenu("Edit");
    QAction *newFile = new QAction(tr("New"),this);
    newFile->setShortcut(tr("Ctrl+F"));

    connect(newFile,SIGNAL(triggered()),this,SLOT(action()));

    file->addAction(newFile);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNewWindow_triggered()
{
    myDialog *dialog = new myDialog(this);
    dialog->show();

    str *n = new str;

    QObject::connect(dialog,SIGNAL(Simple(QString)),n,SLOT(Simple(QString)));
    QObject::connect(dialog,SIGNAL(Invers(QString)),n,SLOT(Inversia(QString)));
    QObject::connect(dialog,SIGNAL(Register(QString)),n,SLOT(Register(QString)));
    QObject::connect(dialog,SIGNAL(RegisterAndInvers(QString)),n,SLOT(All(QString)));
}

void MainWindow::on_actionClose_triggered()
{
    close();
}
