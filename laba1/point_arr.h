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
int Load_point_arr(vertex_arr &vertex, IN_Stream &stream);

int Allocate_Point_arr(vertex_arr &vertex);
int Free_Point_arr(vertex_arr &vertex);

//запись массива точек в файл
int Save_point_arr(const vertex_arr &vertex, OUT_Stream &stream);

int Get_N_vertex(const vertex_arr &vertex);

Point Get_Point(const vertex_arr &vertex, int i);

Point* Get_vertex_arr(const vertex_arr &vertex);

#endif // POINT_ARR_H
