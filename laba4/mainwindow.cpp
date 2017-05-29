#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = new QVBoxLayout;
    ui->centralWidget->setLayout(layout);
    layout->addWidget(lift.GetWidget());
}

MainWindow::~MainWindow()
{
   delete layout;
   delete ui;
}
