#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include "work.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include "my_scene.h"

#define POINT_SIZE 3

namespace Ui {
class MyGraphicView;
}

class MyGraphicView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();
    void Paint(Model &mod);
    void Paint(QGraphicsScene *scene);
    void Connect();
signals:
    void SendScene(My_Scene* my_scene);
private slots:
    //void ChangeScene();
private:
    //void resizeEvent(QResizeEvent *event);

    Ui::MyGraphicView *ui;
    My_Scene my_scene;


    QGraphicsScene      *scene;     // Объявляем сцену для отрисовки
    QGraphicsItemGroup  *group_1;   // Объявляем первую группу элементов

    void deleteItemsFromScene();

};

#endif // MYGRAPHICVIEW_H
