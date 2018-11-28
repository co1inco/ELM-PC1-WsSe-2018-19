#include "label.h"
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QApplication>
#include <QTimer>

#include "mainwindow.h"


long _map(long value, long x1, long x2, long y1, long y2) {
    return (value - x1) * (y2 - y1) / (x2 - x1) + y1;
}

bool serialConnection = false;

conInfoLb::conInfoLb(QWidget *parent) : QWidget(parent)
{
    lb = new QLabel(this);
    lb->setText("                                                   ");
    lb->move(5, 5);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &conInfoLb::_update);
    timer->start(100);
}
void conInfoLb::_update()
{
    if (serialConnection == true)
        lb->setText("Serial device connected");
    else
        lb->setText("Serial device not connected");
}


lastPotiLb::lastPotiLb(QWidget *parent) : QWidget(parent)
{
    lb = new QLabel(this);
    lb->setText("000000");
    lb->move(5, 20);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &lastPotiLb::updateDisplay);
    timer->start(100);
}
void lastPotiLb::updateDisplay(){
    char s[6];
    if (voltCheckedG == false){
        sprintf_s(s, 6, " %04i", potiValueG);
    } else {
        int potiVolt = _map(potiValueG, 0, 1023, 0, 500);
        sprintf_s(s, 6, "%i.%02i", potiVolt / 100, potiVolt % 100);
    }
    lb->setText(s);
}

//int mittelwValueG;

mittelwLb::mittelwLb(QWidget *parent) : QWidget(parent)
{
    lb = new QLabel(this);
    lb->setText("000000");
    lb->move(5, 5);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &mittelwLb::updateDisplay);
    timer->start(100);
}
void mittelwLb::updateDisplay(){
    char s[6];
    sprintf_s(s, 6, "%04i", mittelwValueG);
    lb->setText(s);
}
