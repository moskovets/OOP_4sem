#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *layout = new QHBoxLayout;
    ui->centralWidget->setLayout(layout);
    this->setWindowTitle("Лабораторная работа №2");

    myPicture   = new MyGraphicView();
    layout->addWidget(myPicture);

    myController   = new MyController();
    layout->addWidget(myController);
    myController->setFixedWidth(253);

    QObject::connect(myController, SIGNAL(AnswerChange(Model&)),
            this, SLOT(answerChange(Model&)));
}
void MainWindow::answerChange(Model& mod)
{
    PaintAnswer(mod);
}

MainWindow::~MainWindow()
{
    delete myPicture;
    delete myController;
    delete ui;
}

void MainWindow::PaintAnswer(Model& mod)
{
    myPicture->Paint(mod);
}
