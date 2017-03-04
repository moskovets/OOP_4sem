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

private slots:
    //void ChangeScene();
private:
    //void resizeEvent(QResizeEvent *event);

    Ui::MyGraphicView *ui;


    QGraphicsScene      *scene;     // Объявляем сцену для отрисовки
    QGraphicsItemGroup  *group_1;   // Объявляем первую группу элементов

    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

};

#endif // MYGRAPHICVIEW_H
