#include "queuewd.h"
#include "mainwindow.h"

//#include <QScrollArea>
#include <QVBoxLayout>
#include <QDebug>
#include <QScrollBar>
#include <QTimer>

//#include "queue.h"
Queue *potiQueueG;

bool potiQueueShow = false; //default show queue

queueWd::queueWd(QWidget *parent) : QWidget(parent)
{
    potiQueueG = new Queue();

//    queueWd::_update();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &queueWd::_update);
    timer->start(100);
}


void queueWd::initScrollbar()
{
    QVBoxLayout *layout = new QVBoxLayout;

    int i;
    for (i=0; i<20;i++){
        QLabel *tmp = new QLabel(this);
        tmp->setText("blöa");
        layout->addWidget(tmp);
    }

    QScrollArea *scroll = new QScrollArea(this);
    QWidget *containerWidget = new QWidget;

    containerWidget->setLayout(layout);
    containerWidget->resize(containerWidget->sizeHint());
    scroll->setWidget(containerWidget);
    scroll->resize(110, 120);

    scroll->show();
}

void queueWd::initScrollbar(int nums[], int size)
{
    QVBoxLayout *layout = new QVBoxLayout;

    int i;
    for (i=0; i<size;i++){
        QLabel *tmp = new QLabel(this);
        char s[6];
        sprintf_s(s, "%04i", nums[i]);
        tmp->setText(s);
        layout->addWidget(tmp);
    }

    QScrollArea *scroll = new QScrollArea(this);
    QWidget *containerWidget = new QWidget;

    containerWidget->setLayout(layout);
    containerWidget->resize(containerWidget->sizeHint());
    scroll->setWidget(containerWidget);
    scroll->resize(65, 120); //get minimum value from
    scroll->show();
}


void queueWd::_update()
{
    int q[QUEUE_LENGTH];
    if (potiQueueShow == true){
        int count = potiQueueG->getCount();
        if ((queueSize != count) || (potiQueueShow != showQueueOld)){
            int size = potiQueueG->getQueue(q);
            queueWd::initScrollbar(q, size);
            queueSize = count;
        }
    } else {
         queueWd::initScrollbar(q, 0);
    }
    showQueueOld = potiQueueShow;
}

