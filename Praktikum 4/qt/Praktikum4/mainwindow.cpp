#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clock.h"

#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QMenuBar>

#include "queuewd.h"

bool voltCheckedG = false;
int potiValueG = -1;
int mittelwValueG = -1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //to Connect Button

    initStatusbar();
    initMenubar();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initStatusbar(){
//    statusbar = statusBar();
    statusBar()->showMessage("Ready");

    Clock *c = new Clock(this);
    statusBar()->addPermanentWidget(c);
}

void MainWindow::initMenubar()
{

    QMenu *Filemenu;

    QAction *ExitAct;

    Filemenu = menuBar()->addMenu(tr("&File"));
    /*
    saveAct = new QAction(tr("&Save"), this);
    connect(saveAct, &QAction::triggered, this, &MainWindow::test);
    Filemenu->addAction(saveAct);

    newAct = new QAction(tr("&New"), this);
    newAct->setStatusTip("Python wäre besser");
    connect(newAct, &QAction::triggered, this, &MainWindow::test);
    Filemenu->addAction(newAct);
    */
    Filemenu->addSeparator();

    ExitAct = new QAction(tr("E&xit"), this);
    ExitAct->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    ExitAct->setStatusTip("Exit Application");
    connect(ExitAct, &QAction::triggered, this, &MainWindow::exit);
    Filemenu->addAction(ExitAct);
}


void MainWindow::testDebug(){
    qDebug() << "test";
}

void MainWindow::exit(){
    qApp->quit();
}

void MainWindow::errorMessage(char s[])
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText(s);
    msgBox->exec();
}

void MainWindow::on_decimal_toggled(bool checked)
{
    voltCheckedG = checked;
}

void MainWindow::on_disPotiBtn_clicked()
{
    if (serialConnection == true){
        int v = dsp->readPoti();
        if (potiQueueG->addItem(v)){
            potiValueG = v;
        } else {
            errorMessage("Queue Full");
        }
    } else {
        errorMessage("Serial Device not connected");
    }
}

void MainWindow::on_delQueueBtn_clicked()
{
    potiQueueG->clear();
}

void MainWindow::on_dispQueueBtn_toggled(bool checked)
{
    potiQueueShow = checked;
}

void MainWindow::on_connectBtn_clicked()
{
    if (serialConnection == false){
        Display *dsp = new Display();
        if (dsp->init() == false){
            errorMessage("Unable to connect to serial device");
            serialConnection = false;
        } else {
            serialConnection = true;
        }
    } else {
        serialConnection = false;
    }
}

void MainWindow::on_mittelwertBtn_clicked()
{
    int size = potiQueueG->getCount();
    int sum = potiQueueG->getSum();

    mittelwValueG = sum / size;
}
