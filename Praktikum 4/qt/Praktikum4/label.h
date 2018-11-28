#ifndef LABEL_H
#define LABEL_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>

extern bool serialConnection;

class conInfoLb : public QWidget
{
    Q_OBJECT
public:
    conInfoLb(QWidget *parent = nullptr);
    conInfoLb(QMainWindow *parent = nullptr);

signals:

public slots:
    void _update();

public:

private:
    QLabel *lb;

};


extern bool voltCheckedG;
extern int potiValueG;

class lastPotiLb : public QWidget
{
    Q_OBJECT
public:
    lastPotiLb(QWidget *parent = nullptr);

signals:

public slots:
    void updateDisplay();

public:

private:
    QLabel *lb;
};


extern int mittelwValueG;

class mittelwLb : public QWidget
{
    Q_OBJECT
public:
    mittelwLb(QWidget *parent = nullptr);

signals:

public slots:
    void updateDisplay();

public:

private:
    QLabel *lb;
};

#endif // LABEL_H
