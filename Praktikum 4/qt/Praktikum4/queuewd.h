#ifndef QUEUEWD_H
#define QUEUEWD_H

#include "queue.h"

#include <QWidget>
#include <QLabel>
#include <QScrollArea>

#include "mainwindow.h"

extern Queue *potiQueueG;
extern bool potiQueueShow;


class queueWd : public QWidget
{
    Q_OBJECT
public:
    queueWd(QWidget *parent = nullptr);

signals:

public slots:
    void _update();

public:
    void initScrollbar();
    void initScrollbar(int nums[], int size);

private:

    int potiQueueL[QUEUE_LENGTH];
    int queueSize;
    bool showQueueOld;
    QLabel *lb;

};

#endif // QUEUEWD_H
