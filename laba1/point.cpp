#include "point.h"
int Download_point_arr(std::ifstream &inp, Point* arr, const int N)
{
    double x, y, z;
    int flag = 0;
    for(int i = 0; i < N; i++) {
        if(inp >> x && inp >> y && inp >> z) {
            arr[i].x = x;
            arr[i].y = y;
            arr[i].z = z;
        }
        else {
            flag = 1;
        }
    }
    return flag;
}
void Save_point_arr(std::ofstream &out, const Point* arr, const int N)
{
    for(int i = 0; i < N; i++) {
        out << arr[i].x << " " << " " << arr[i].y << " " <<
               arr[i].z << "\n";
    }
}


static void Mult(t_vect vec, const t_matrix a)
{
    t_vect res = {0};
    for(int i = 0; i < N_DIMEN; i++) {
        for(int j = 0; j < N_DIMEN; j++) {
            res[i] += a[i][j] * vec[j];
        }
    }
    for(int i = 0; i < N_DIMEN; i++) {
        vec[i] = res[i];
    }
}

static void Mult_matrix(t_matrix res, const t_matrix a, const t_matrix b)
{
    for(int i = 0; i < N_DIMEN; i++) {
        for(int j = 0; j < N_DIMEN; j++) {
            res[i][j] = 0;
            for(int k = 0; k < N_DIMEN; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void GetResultMatrix(t_matrix a, const Rotate &act)
{
    t_matrix ax = { { 1, 0, 0 },
                       { 0, cos(act.x_angle), -sin(act.x_angle) },
                       { 0, sin(act.x_angle), cos(act.x_angle) } };
    t_matrix ay = { { cos(act.y_angle), 0, sin(act.y_angle) },
                       { 0, 1, 0 },
                       { -sin(act.y_angle), 0, cos(act.y_angle) } };
    t_matrix az = { { cos(act.z_angle), -sin(act.z_angle), 0 },
                       { sin(act.z_angle), cos(act.z_angle), 0 },
                       { 0, 0, 1 } };
    t_matrix tmp;
    Mult_matrix(tmp, ax, ay);
    Mult_matrix(a, tmp, az);

}


void Rotate_point_arr(Point* arr, const int N_arr, const Rotate &act)
{
    t_matrix m;
    GetResultMatrix(m, act);

    t_vect vec;
    for(int i = 0; i < N_arr; ++i) {
        vec[0] = arr[i].x;
        vec[1] = arr[i].y;
        vec[2] = arr[i].z;
        Mult(vec, m);
        arr[i].x = vec[0];
        arr[i].y = vec[1];
        arr[i].z = vec[2];
    }
}

void Scale_point_arr(Point* arr, const int N_arr, const Scale &act)
{
    t_matrix m = { { act.kx, 0, 0 },
                   { 0, act.ky, 0 },
                   { 0, 0, act.kz } };
    t_vect vec;
    for(int i = 0; i < N_arr; ++i) {
        vec[0] = arr[i].x;
        vec[1] = arr[i].y;
        vec[2] = arr[i].z;
        Mult(vec, m);
        arr[i].x = vec[0];
        arr[i].y = vec[1];
        arr[i].z = vec[2];
    }
}

void Move_point_arr(Point* arr, const int N_arr, const Move &act)
{
    for(int i = 0; i < N_arr; ++i) {
        arr[i].x += act.dx;
        arr[i].y += act.dy;
        arr[i].z += act.dz;
    }
}
