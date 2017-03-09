#ifndef POINT_H
#define POINT_H

#include "action.h"
#include "my_scene.h"

#include <math.h>
#include <fstream>
#define  N_DIMEN 3 //DIMENSIONALITY

struct Point {
    double x;
    double y;
    double z;
};

//тип для хранения матриц преобразование в N-мерном пр-ве
typedef double t_matrix[N_DIMEN][N_DIMEN];

//тип для хранения вектора-точки в N-мерном пр-ве
typedef double t_vect[N_DIMEN];

//получние результирующей матрицы поворота по 3-м углам
void GetResultMatrix(t_matrix a, const Rotate &act);

//преобразование массива точек
void Rotate_point_arr(Point* arr, const int N_arr, const Rotate &act);
void Scale_point_arr(Point* arr, const int N_arr, const Scale &act);
void Move_point_arr(Point* arr, const int N_arr, const Move &act);

//загрузка массива точек опр. длины из файла
int Load_point_arr(std::ifstream &inp, Point **arr, int &N);
int Load_point(std::ifstream &inp, Point& p);
int Allocate_Point_arr(Point **arr, const int N);
int Free_Point_arr(Point** arr);

//запись массива точек в файл
int Save_point_arr(std::ofstream &out, const Point* arr, const int N);
int Save_point(std::ofstream &out, const Point& p);

int Draw_line(My_Scene &scene, const Point &a, const Point &b);
#endif // POINT_H
