#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(200, 300);

    QVBoxLayout *layout = new QVBoxLayout;
    ui->centralWidget->setLayout(layout);
    this->setWindowTitle("Лабораторная работа №4");
    for(int i = 0; i < FLOOR_NUMBERS; i++) {
        buttons[i] = new CButton;
        layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));
        buttons[i]->SetNumberFloor(i);
        buttons[i]->setText(QString::number(i));
    }
}

MainWindow::~MainWindow()
{
   for(int i = 0; i < FLOOR_NUMBERS; i++) {
        delete buttons[i];
   }
   delete ui;
}
