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
    this->setWindowTitle("Лабораторная работа №1");
    myController   = new MyController();
    layout->addWidget(myController);
    myController->setFixedWidth(253);

    myPicture   = new MyGraphicView();
    layout->addWidget(myPicture);


    QObject::connect(myController, SIGNAL(AnswerChange(Model&)),
            this, SLOT(answerChange(Model&)));

    QObject::connect(myController, SIGNAL(SceneChange(QGraphicsScene*)),
            this, SLOT(sceneChange(QGraphicsScene*)));

    QObject::connect(myPicture, SIGNAL(SendScene(My_Scene*)),
            this, SLOT(SendingScene(My_Scene*)));
    myPicture->Connect();
}
void MainWindow::answerChange(Model& mod)
{
    PaintAnswer(mod);
}
void MainWindow::sceneChange(QGraphicsScene *scene)
{
    PaintScene(scene);
}
void MainWindow::SendingScene(My_Scene* my_scene)
{
    std::cout << "window:" << my_scene->x_center << endl;
    myController->GetScene(my_scene);
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
void MainWindow::PaintScene(QGraphicsScene *scene)
{
    myPicture->Paint(scene);
}
