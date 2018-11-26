#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMenubar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenubar()
{
    Filemenu = menuBar()->addMenu(tr("&File"));

    impMenu = new QMenu(tr("&Import"), this);
    impAct = new QAction("Import something", this);
    impAct->setStatusTip("Does nothing");
//    connect(impAct, &QAction::triggered, this, MainWindow::test());
    impMenu->addAction(impAct);
    Filemenu->addMenu(impMenu);

    Filemenu->addSeparator();

    ExitAct = new QAction(tr("E&xit"), this);
    ExitAct->setShortcut('Ctrl+X');
    ExitAct->setStatusTip("Exit Application");
 //   connect(ExitAct, &QAction::triggered, this, MainWindow::exit());
    Filemenu->addAction(ExitAct);

}

void MainWindow::test(){
    printf("test");
}

void MainWindow::exit(){
    qApp->quit();
}
