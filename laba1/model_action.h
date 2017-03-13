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

int Get_N_vertex(const Model &model);

int Get_N_edges(const Model &model);

vertex_arr Get_vertex_arr(const Model &model);
//Point* Get_vertex_arr(const Model &model);
edges_arr Get_edges_arr(const Model &model);
//t_edge* Get_edges_arr(const Model &model);

#endif // MODEL_ACTION_H
