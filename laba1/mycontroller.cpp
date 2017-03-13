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
    Validator = new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$"));
    ui->dxEdit->setValidator(Validator);
    ui->dyEdit->setValidator(Validator);
    ui->dzEdit->setValidator(Validator);
    ui->kxEdit->setValidator(Validator);
    ui->kyEdit->setValidator(Validator);
    ui->kzEdit->setValidator(Validator);
    ui->rot_xEdit->setValidator(Validator);
    ui->rot_yEdit->setValidator(Validator);
    ui->rot_zEdit->setValidator(Validator);
}
void MyController::GetScene(My_Scene *scene1) {
    this->scene.x_center = scene1->x_center;
    this->scene.y_center = scene1->y_center;
    this->scene.scene = scene1->scene;
}

MyController::~MyController()
{
    t_action act;
    act.free = true;
    delete Validator;
    main_controller(scene, act, FREE);
    delete ui;
}

//получение данных с выбранных полей
double * MyController::GetData(vector <QLineEdit*> &vec)
{
    QString str;
    double *data = new double[vec.size()];
    double x;
    QString mess;
    for(unsigned int i = 0; i < vec.size(); i++) {
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


    t_action act;

    act.rotat.x_angle = data[0] * M_PI / 180;
    act.rotat.y_angle = data[1] * M_PI / 180;
    act.rotat.z_angle = data[2] * M_PI / 180;

    main_controller(scene, act, ROTATE);
    main_controller(scene, act, DRAW);
    delete[] data;
}

void MyController::on_scaleButton_clicked()
{

    vector<QLineEdit*> edits;
    edits.push_back(ui->kxEdit);
    edits.push_back(ui->kyEdit);
    edits.push_back(ui->kzEdit);

    double *data = GetData(edits);

    if(LineEditError != NO_ER)
        return;

    t_action act;

    act.scal.kx = data[0];
    act.scal.ky = data[1];
    act.scal.kz = data[2];

    main_controller(scene, act, SCALE);
    main_controller(scene, act, DRAW);
    delete[] data;

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


    t_action act;

    act.mov.dx = data[0];
    act.mov.dy = data[1];
    act.mov.dz = data[2];

    main_controller(scene, act, MOVE);
    main_controller(scene, act, DRAW);
    delete[] data;
}


void MyController::on_fileButton_clicked()
{

    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if(str == "")
        return;
    t_action act;
    strcpy(act.creat.fileName, str.toStdString().c_str());
    int res = main_controller(scene, act, CREATE);
    QString mess = "";
    if(res == FILE_NOT_FIND) {
        mess = "Cannot open file";
    } else if(res == FILE_ERROR) {
        mess = "Error format of data";
    } else if(res == MEMORY_ERROR) {
        mess = "Mamory error";
    }
    if(mess != "") {
        QErrorMessage errorMessage;
        errorMessage.showMessage(mess);
        errorMessage.exec();
        return;
    }
    main_controller(scene, act, DRAW);
}


void MyController::on_saveButton_clicked()
{
setlocale (LC_ALL, "C");
    QString str = QFileDialog::getSaveFileName(0, "Save Dialog", "", "*.txt");
    if(str == "")
        return;
    t_action act;
    strcpy(act.creat.fileName, str.toStdString().c_str());
    int res = main_controller(scene, act, SAVE);
    QString mess = "";
    if(res == FILE_NOT_FIND) {
        mess = "Cannot open file";
    } else if(res == FILE_ERROR) {
        mess = "Error format of data";
    }
    if(mess != "") {
        QErrorMessage errorMessage;
        errorMessage.showMessage(mess);
        errorMessage.exec();
        return;
    }
}
