#include <QPen>
#include "draw_on_scene.h"

const QPen penBlack(Qt::black); // Задаём чёрную кисть


int Draw_2d_line(My_Scene &scene, double x1, double y1,
                 double x2, double y2) {
    if(!scene.scene) {
        return SCENE_NOT_FOUND;
    }
    scene.scene->addLine(scene.x_center + x1,
                         scene.y_center - y1,
                         scene.x_center + x2,
                         scene.y_center - y2,
                         penBlack);
    return 0;
}

int Clean_Scene(My_Scene &scene) {
    if(!scene.scene) {
        return SCENE_NOT_FOUND;
    }
    foreach( QGraphicsItem *item, scene.scene->items()) {
       delete item;
    }
}
