#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clock.h"
#include <QMessageBox>
#include <QDebug>
#include <QLabel>

#include <QMenu>
#include <QMenuBar>
#include <QHoverEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStatusbar();
    initMenubar();
    initBody();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenubar()
{

    QMenu *Filemenu;
    QMenu *impMenu;
    QMenu *editMenu;
    QMenu *extraMenu;

    QAction *ExitAct;
    QAction *impAct;
    QAction *saveAct;
    QAction *newAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *helpAct;
    QAction *infoAct;

    Filemenu = menuBar()->addMenu(tr("&File"));

    saveAct = new QAction(tr("&Save"), this);
    connect(saveAct, &QAction::triggered, this, &MainWindow::test);
    Filemenu->addAction(saveAct);

    newAct = new QAction(tr("&New"), this);
    newAct->setStatusTip("Python wäre besser");
    connect(newAct, &QAction::triggered, this, &MainWindow::test);
    Filemenu->addAction(newAct);

    impMenu = new QMenu(tr("&Import"), this);
    impAct = new QAction("Import something", this);
    impAct->setStatusTip("Import better programing language");
    impAct->setStatusTip("Does nothing");
    connect(impAct, &QAction::triggered, this, &MainWindow::test);
    impMenu->addAction(impAct);
    Filemenu->addMenu(impMenu);

    Filemenu->addSeparator();

    ExitAct = new QAction(tr("E&xit"), this);
    ExitAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    ExitAct->setStatusTip("Exit Application");
    connect(ExitAct, &QAction::triggered, this, &MainWindow::exit);
    Filemenu->addAction(ExitAct);


    editMenu = menuBar()->addMenu(tr("&Bearbeiten"));

    undoAct = new QAction(tr("&Rückgängig"), this);
    undoAct->setStatusTip("Mach C++ Rückgängig");
    connect(undoAct, &QAction::triggered, this, &MainWindow::testDebug);
    editMenu->addAction(undoAct);

    redoAct = new QAction(tr("&Wiederherstellen"), this);
    redoAct->setStatusTip("Falsche richtung, buddy");
    connect(redoAct, &QAction::triggered, this, &MainWindow::testDebug);
    editMenu->addAction(redoAct);


    extraMenu = menuBar()->addMenu(tr("&Extra"));

    helpAct = new QAction(tr("&Help"), this);
    helpAct->setStatusTip("Die brauchst du auch. Du benutzt C++.");
//    connect(helpAct, &QAction::triggered, this, &MainWindow::testDebug);
    extraMenu->addAction(helpAct);

    infoAct = new QAction(tr("&Info"), this);
    infoAct->setStatusTip("Comment not available");
    connect(infoAct, &QAction::triggered, this, &MainWindow::testDebug);
    extraMenu->addAction(infoAct);


}

void MainWindow::initStatusbar(){
//    statusbar = statusBar();
    statusBar()->showMessage("Ready");

    Clock *c = new Clock(this);
    statusBar()->addPermanentWidget(c);
}

void MainWindow::initBody(){

//    connect(frame_2, &QHoverEvent, this, &MainWindow::test);
}


void MainWindow::test(){
    int reply;
    int x = QMessageBox::Yes;
    reply = QMessageBox::question(this, "test", "test",  QMessageBox::Yes|QMessageBox::No);
    qDebug() << reply << x;
}
void MainWindow::testDebug(){
    qDebug() << "test";
}

void MainWindow::exit(){
    qApp->quit();
}

void MainWindow::on_pushButton_clicked()
{
    test();
}

void test(){
    printf("test");
}

