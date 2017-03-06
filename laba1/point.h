#ifndef POINT_H
#define POINT_H

#include "action.h"
#include <math.h>
#include <fstream>
#define  N_DIMEN 3 //DIMENSIONALITY
struct Point {
    double x;
    double y;
    double z;
};
typedef double t_matrix[N_DIMEN][N_DIMEN];
typedef double t_vect[N_DIMEN];

void GetResultMatrix(t_matrix a, const Rotate &act);

void Rotate_point_arr(Point* arr, const int N_arr, const Rotate &act);

void Scale_point_arr(Point* arr, const int N_arr, const Scale &act);

void Move_point_arr(Point* arr, const int N_arr, const Move &act);

static void Mult(t_vect vec, const t_matrix a);

static void Mult_matrix(t_matrix res, const t_matrix a, const t_matrix b);

int Download_point_arr(std::ifstream &inp, Point* arr, const int N);
#endif // POINT_H
