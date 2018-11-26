#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void initMenubar();
    void test();
    void exit();

    Ui::MainWindow *ui;

    QMenu *Filemenu;
    QMenu *Viewmenu;
    QMenu *Extramenu;
    QMenu *impMenu;

    QAction *ExitAct;
    QAction *HelpAct;
    QAction *EditAct;
    QAction *impAct;


};

#endif // MAINWINDOW_H
