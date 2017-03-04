#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mycontroller.h"
#include <mygraphicview.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void PaintAnswer(Model &mod);

private slots:
    void answerChange(Model &mod);
private:
    Ui::MainWindow  *ui;
    MyGraphicView   *myPicture;     // Наш кастомный виджет
    MyController    *myController;
};


#endif // MAINWINDOW_H
