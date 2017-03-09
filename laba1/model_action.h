#ifndef MODEL_ACTION_H
#define MODEL_ACTION_H

#include "action.h"
#include "model.h"
#include "my_scene.h"

//преобразование модели
int Rotate_model(Model &model, const Rotate &act);
int Scale_model(Model &model, const Scale &act);
int Move_model(Model &model, const Move &act);

//загрузка модели из файла
int DownloadModel(Model &model, const Create &act);

//сохранение модели в файл
int SaveModel(const Model &model, const Create &act);

//освобождения массивов вершин и ребер
int Free_model(Model &model);

//выделения памяти под заданной количество вершин и ребер
int Create_model(Model &model, const int N_v, const int N_e);

int Draw_model(My_Scene &scene, const Model &model);
#endif // MODEL_ACTION_H
