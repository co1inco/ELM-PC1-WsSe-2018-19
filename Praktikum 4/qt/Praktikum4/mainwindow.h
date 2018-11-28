#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <queue.h>

#include "serial/Display.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void exit();
    void errorMessage(char s[]);
    void on_decimal_toggled(bool checked);

    void on_disPotiBtn_clicked();

    void on_delQueueBtn_clicked();

    void on_dispQueueBtn_toggled(bool checked);

    void on_connectBtn_clicked();

    void on_mittelwertBtn_clicked();

private:
    void initMenubar();
    void initStatusbar();
    void testDebug();

    Display *dsp;

//    bool serialCon;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
