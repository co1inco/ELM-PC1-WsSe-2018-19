#ifndef CLOCK_H
#define CLOCK_H

#include <QLabel>
#include <QMainWindow>

class Clock : public QLabel
{
    Q_OBJECT
public:
//    explicit Clock(QLabel *parent = nullptr);
    Clock(QLabel *parent = nullptr);
    Clock(QWidget *parent = nullptr);
    Clock(QMainWindow *parent = nullptr);

    void loop();
    void stop();

signals:

public slots:

private:

    bool runLoop;
    char timeformat[10] = "%H:%M:%S";
    QTimer *timer;

private slots:
        void _update();

};

#endif // CLOCK_H
