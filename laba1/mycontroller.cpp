#include "mycontroller.h"
#include "ui_mycontroller.h"
#include <QRegExpValidator>
#include <QIntValidator>
#include <QFileDialog>
#include <iostream>
#include <string.h>
#define MIN_PAR 10
Text_Error LineEditError;


MyController::MyController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyController)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    par = parent;
    ui->setupUi(this);
    //ui->aEdit->setValidator(new QIntValidator(11, 1000));
    //ui->bEdit->setValidator(new QIntValidator(11, 1000));
    ui->dxEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->dyEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->dzEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->kxEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->kyEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->kzEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->rot_xEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->rot_yEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
    ui->rot_zEdit->setValidator(new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$")));
}

MyController::~MyController()
{
    t_action act;
    act.free = true;
    main_controller(model, act, FREE);
    delete ui;
}

//получение данных с выбранных полей
double * MyController::GetData(vector <QLineEdit*> &vec)
{
    QString str;
    double *data = new double[vec.size()];
    double x;
    QString mess;
    for(int i = 0; i < vec.size(); i++) {
        str = vec[i]->text();
        x = Analiz_Text(str);
        switch(LineEditError)
        {
        case EMPTY:
            mess = "Область текста пуста.\n Введите данные!";
            break;
        case E_SYMBOL:
            mess = "Ошибочный символ\n "
                   "Разрешается использование только цифр, '.'',' и знаков табуляции";
            break;
        }
        if(LineEditError != NO_ER) {
            QErrorMessage errorMessage;
            errorMessage.showMessage(mess);
            errorMessage.exec();
            break;
        }
        data[i] = x;
    }
   return data;
}
//анализ строки данных (проверка, явл-тся ли вещественным числом)
double Analiz_Text(QString str)
{
    LineEditError = NO_ER;
    if(str == "") {
        LineEditError = EMPTY;
        return 0;
    }
    str.replace(QString(","), QString("."));
    //str.replace(QString("\n"), QString(" "));

    QStringList list = str.split(' ', QString::SkipEmptyParts);
    if(list.size() > 1) {
        LineEditError = E_SYMBOL;
        return 0;
    }

    double x;
    bool ok = true;
    for(int i = 0; i < list.size(); i++) {
        x = list.at(i).toDouble(&ok);
        //cout << tmp.toStdString() << " " << ok << " " << x << endl;
        if(!ok) {
            LineEditError = E_SYMBOL;
            return 0;
        }
    }
    return x;
}


void MyController::on_rotateButton_clicked()
{
    vector<QLineEdit*> edits;
    edits.push_back(ui->rot_xEdit);
    edits.push_back(ui->rot_yEdit);
    edits.push_back(ui->rot_zEdit);

    double *data = GetData(edits);

    if(LineEditError != NO_ER)
        return;

    if(model.N_v == 0)
        return;

    t_action act;

    act.rotat.x_angle = data[0] * M_PI / 180;
    act.rotat.y_angle = data[1] * M_PI / 180;
    act.rotat.z_angle = data[2] * M_PI / 180;

    main_controller(model, act, ROTATE);

    emit AnswerChange(model);
}

void MyController::on_scaleButton_clicked()
{
    //TODO
    emit AnswerChange(model);

}

void MyController::on_moveButton_clicked()
{
    vector<QLineEdit*> edits;
    edits.push_back(ui->dxEdit);
    edits.push_back(ui->dyEdit);
    edits.push_back(ui->dzEdit);

    double *data = GetData(edits);

    if(LineEditError != NO_ER)
        return;

    if(model.N_v == 0)
        return;

    t_action act;

    act.mov.dx = data[0];
    act.mov.dy = data[1];
    act.mov.dz = data[2];

    main_controller(model, act, MOVE);

    emit AnswerChange(model);
}


void MyController::on_fileButton_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if(str == "")
        return;
    t_action act;
    strcpy(act.creat.fileName, str.toStdString().c_str());
    main_controller(model, act, CREATE);

    emit AnswerChange(model);
}
