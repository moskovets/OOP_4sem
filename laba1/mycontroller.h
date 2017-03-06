#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include "work.h"

#include <QWidget>
#include <QtGui>
#include <QErrorMessage>
#include <QString>
#include <QStringList>
#include <string>
#include <stdio.h>
#include <vector>
#include <QLineEdit>

using namespace std;
enum Text_Error { EMPTY, E_SYMBOL, E_PAIR_DATA, E_FEW_POINT, NO_ER };


namespace Ui {
class MyController;
}

class MyController : public QWidget
{
    Q_OBJECT

public:
    explicit MyController(QWidget *parent = 0);
    ~MyController();
signals:
    void AnswerChange(Model &mod);
private slots:
    void on_rotateButton_clicked();

    void on_scaleButton_clicked();

    void on_moveButton_clicked();

    void on_fileButton_clicked();

    //void on_xhorizontalSlider_valueChanged(int value);

    void on_saveButton_clicked();

private:

    double *GetData(vector <QLineEdit*> &vec);


    Ui::MyController *ui;
    Model model;
    QWidget *par;

};

double Analiz_Text(QString str);
#endif // MYCONTROLLER_H
