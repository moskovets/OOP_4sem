#ifndef POINT_ARR_H
#define POINT_ARR_H
#include "point.h"
//преобразование массива точек
int Rotate_point_arr(Point* arr, const int N_arr, const Rotate &act);
int Scale_point_arr(Point* arr, const int N_arr, const Scale &act);
int Move_point_arr(Point* arr, const int N_arr, const Move &act);

//загрузка массива точек опр. длины из файла
int Load_point_arr(std::ifstream &inp, Point **arr, int &N);

int Allocate_Point_arr(Point **arr, const int N);
int Free_Point_arr(Point** arr);

//запись массива точек в файл
int Save_point_arr(std::ofstream &out, const Point* arr, const int N);

#endif // POINT_ARR_H
