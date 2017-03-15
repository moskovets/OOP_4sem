#ifndef POINT_H
#define POINT_H

#include "action.h"
#include "my_scene.h"
#include "my_stream.h"
#define BUFF_SIZE 100

#include <math.h>
#include <fstream>
#define  N_DIMEN 4 //DIMENSIONALITY

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

void GetResultMatrix(t_matrix a, const Scale &act);
void GetResultMatrix(t_matrix a, const Move &act);

//конвертация точки в вектор
int From_vec_to_Point(Point &p, const t_vect &vec);
int From_Point_to_vec(t_vect &vec, const Point &p);

//Применение матрицы преобразований к одной точке
int Change_Point_with_matrix(Point &p, const t_matrix &m_rotate);

//загрузка точки опр. длины из файла
int Load_point(Point& p, IN_Stream &stream);

//запись точки в файл
int Save_point(const Point& p, OUT_Stream &stream);

int Draw_line(My_Scene &scene, const Point &a, const Point &b);
#endif // POINT_H
