#include "clock.h"
#include <QDateTime>
#include <unistd.h>

#include <QTimer>
//using namespace std;

Clock::Clock(QLabel *parent) : QLabel(parent)
{
    this->setParent(parent);
    this->setText("text");
    runLoop = true;
//    loop();

}
Clock::Clock(QWidget *parent) : QLabel(parent)
{
    this->setParent(parent);
    this->setText("text");
    runLoop = true;
    QDateTime now = QDateTime::currentDateTime();
    this->setText(now.time().toString());

}
Clock::Clock(QMainWindow *parent) : QLabel(parent)
{
    this->setParent(parent);
    this->setText("text");
    runLoop = true;

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::_update);
    timer->start(100);
}

void Clock::_update(){
    QDateTime now = QDateTime::currentDateTime();
    this->setText(now.time().toString());
    this->update();
}

void Clock::stop(){
    runLoop = false;
}
