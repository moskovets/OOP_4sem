#ifndef DRAW_ON_SCENE_H
#define DRAW_ON_SCENE_H

#include "my_scene.h"
#include "errors.h"

int Draw_2d_line(My_Scene &scene, double x1, double y1,
                 double x2, double y2);

int Clean_Scene(My_Scene &scene);

#endif // DRAW_ON_SCENE_H
