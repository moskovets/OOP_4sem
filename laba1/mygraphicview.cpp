#include "mygraphicview.h"
#include "ui_mygraphicview.h"
#include <iostream>

MyGraphicView::MyGraphicView(QWidget *parent) :
     QGraphicsView(parent),
    ui(new Ui::MyGraphicView)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    my_scene.scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(my_scene.scene);          // Устанавливаем сцену в виджет
    int width = this->width();
    int height = this->height();
    my_scene.scene->setSceneRect(0,0,width,height);
    my_scene.x_center = width / 2;
    my_scene.y_center = height / 2;
    //std::cout << width << " " << height << std::endl;


    //group_1 = new QGraphicsItemGroup(); // Группа для отрисовки прямоугольника

    //scene->addItem(group_1);
    //Model mod;
    //Paint(mod);
    ui->setupUi(this);
   // emit SendScene(&my_scene);

}

void MyGraphicView::Paint(QGraphicsScene *scene1) {
//    this->setScene(scene1);          // Устанавливаем сцену в виджет
//    int width = this->width();
//    int height = this->height();
//    scene1->setSceneRect(0,0,width,height);
    //scene1->sceneRect().height();
}
void MyGraphicView::Connect()
{
    emit SendScene(&my_scene);
}

void MyGraphicView::Paint(Model &model) {
    this->setScene(scene);          // Устанавливаем сцену в виджет
    this->deleteItemsFromScene();
    int width = this->width();
    int height = this->height();

    /* Устанавливаем размер сцены по размеру виджета
     * Первая координата - это левый верхний угол,
     * а Вторая - это правый нижний угол
     * */
    scene->setSceneRect(0,0,width,height);

    QPen penBlack(Qt::black); // Задаём чёрную кисть

    double cx = width/2;
    double cy = height/2;
   //group_1->addToGroup(scene->addLine(cx + 30, cy - 20,
   //         cx - 100, cy - 50, penBlack));
   // std::cout << model.N_e << std::endl;

    for(int i = 0; i < model.N_e; i++) {
       // std::cout << model.edge[i][0] << " " << cx + model.vertex[model.edge[i][0]].x << " "
       //           << (cy - model.vertex[model.edge[i][0]].y) << "  ";
       // std::cout << model.edge[i][1] << " " << cx + model.vertex[model.edge[i][1]].x << " "
       //           << (cy - model.vertex[model.edge[i][1]].y) << " " << std::endl;
       scene->addLine(
                cx + model.vertex[model.edge[i][0]].x, cy - model.vertex[model.edge[i][0]].y,
                cx + model.vertex[model.edge[i][1]].x, cy - model.vertex[model.edge[i][1]].y, penBlack);
    }

}

MyGraphicView::~MyGraphicView()
{
    delete ui;
}

/* Метод для удаления всех элементов из группы
 * */
void MyGraphicView::deleteItemsFromScene()
{
    /* Перебираем все элементы сцены, и если они принадлежат группе,
     * переданной в метод, то удаляем их
     * */
    foreach( QGraphicsItem *item, scene->items()) {
       delete item;
    }
}
