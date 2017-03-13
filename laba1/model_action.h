#ifndef MODEL_ACTION_H
#define MODEL_ACTION_H

#include "action.h"
#include "model.h"
#include "my_scene.h"

Model Init_model();

//преобразование модели
int Rotate_model(Model &model, const Rotate &act);
int Scale_model(Model &model, const Scale &act);
int Move_model(Model &model, const Move &act);

//загрузка модели из файла
int LoadModel(Model &model, const Create &act);

//сохранение модели в файл
int SaveModel(const Model &model, const Create &act);

//освобождения массивов вершин и ребер
int Free_model(Model &model);

int Draw_model(My_Scene &scene, const Model &model);
#endif // MODEL_ACTION_H
