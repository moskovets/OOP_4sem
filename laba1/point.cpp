#include "point.h"
#include "draw_on_scene.h"
#include "errors.h"
int Load_point_arr(std::ifstream &inp, Point** arr, int &N)
{
    if(!(inp >> N)) {
        return FILE_ERROR;
    }
    int ret = 0;
    ret = Allocate_Point_arr(arr, N);
    //arr[0].x = 1;

    for(int i = 0; i < N && !ret; i++) {
        ret = Load_point(inp, (*arr)[i]);
        if(ret) {
            Free_Point_arr(arr);
        }
    }
    return ret;
}
int Load_point(std::ifstream &inp, Point& p)
{
    double x, y, z;
    if(inp >> x && inp >> y && inp >> z) {
        p.x = x;
        p.y = y;
        p.z = z;
    }
    else {
        return FILE_ERROR;
    }
    return 0;
}
int Allocate_Point_arr(Point **arr, const int N) {
    *arr = new Point [N];
    if(!(*arr))
        return MEMORY_ERROR;
    //arr[0].x = 0;
    return 0;
}
int Free_Point_arr(Point** arr) {
    if(*arr)
        delete[] *arr;
    return 0;
}

int Save_point_arr(std::ofstream &out, const Point* arr, const int N)
{
    if(!out)
        return FILE_NOT_FIND;
    out << N << std::endl;
    for(int i = 0; i < N; i++) {
        Save_point(out, arr[i]);
    }
    return 0;
}

int Save_point(std::ofstream &out, const Point& p)
{
    if(!out)
        return FILE_NOT_FIND;
    out << p.x << " " << p.y << " " << p.z << std::endl;
    return 0;
}

void Mult(t_vect vec, const t_matrix a)
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

void Mult_matrix(t_matrix res, const t_matrix a, const t_matrix b)
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

int Draw_line(My_Scene &scene, const Point &a, const Point &b) {

    return Draw_2d_line(scene, a.x, a.y, b.x, b.y);
}
