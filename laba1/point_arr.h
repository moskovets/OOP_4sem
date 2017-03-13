#ifndef POINT_ARR_H
#define POINT_ARR_H
#include "point.h"
struct vertex_arr {
    Point *arr = NULL;
    int N_v = 0;
};
vertex_arr Init_vertex();
//преобразование массива точек
int Rotate_point_arr(vertex_arr &vert, const Rotate &act);
int Scale_point_arr(vertex_arr &vertex, const Scale &act);
int Move_point_arr(vertex_arr &vertex, const Move &act);

//загрузка массива точек опр. длины из файла
int Load_point_arr(vertex_arr &vertex, std::ifstream &inp);

int Allocate_Point_arr(vertex_arr &vertex);
int Free_Point_arr(vertex_arr &vertex);

//запись массива точек в файл
int Save_point_arr(const vertex_arr &vertex, std::ofstream &out);

#endif // POINT_ARR_H
