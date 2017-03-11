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
    }
    if(ret) {
        Free_Point_arr(arr);
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

int Mult(t_vect vec, const t_matrix a)
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
    return 0;
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


int Rotate_point_arr(Point* arr, const int N_arr, const Rotate &act)
{
    if(!arr)
        return MODEL_EMPTY;
    t_matrix m;
    int ret = 0;
    GetResultMatrix(m, act);
    for(int i = 0; i < N_arr && !ret; ++i) {
        ret = Change_Point_with_matrix(arr[i], m);
    }
   return ret;
}
int From_vec_to_Point(Point &p, const t_vect &vec) {
    p.x = vec[0];
    p.y = vec[1];
    p.z = vec[2];
    return 0;
}
int From_Point_to_vec(t_vect &vec, const Point &p) {
    vec[0] = p.x;
    vec[1] = p.y;
    vec[2] = p.z;
    return 0;
}

int Change_Point_with_matrix(Point &p, const t_matrix &m_rotate) {
    t_vect vec;
    int ret = 0;
    ret = From_Point_to_vec(vec, p);
    if(!ret)
        ret = Mult(vec, m_rotate);

    if(!ret)
        ret = From_vec_to_Point(p, vec);
    return ret;
}

int Scale_point_arr(Point* arr, const int N_arr, const Scale &act)
{
    if(!arr)
        return MODEL_EMPTY;

    t_matrix m = { { act.kx, 0, 0 },
                   { 0, act.ky, 0 },
                   { 0, 0, act.kz } };
    int ret = 0;
    for(int i = 0; i < N_arr && !ret; ++i) {
        ret = Change_Point_with_matrix(arr[i], m);
    }
    return ret;
}

int Move_point(Point &p, const Move &act)
{
    p.x += act.dx;
    p.y += act.dy;
    p.z += act.dz;
    return 0;
}

int Move_point_arr(Point* arr, const int N_arr, const Move &act)
{
    if(!arr)
        return MODEL_EMPTY;
    int ret = 0;
    for(int i = 0; i < N_arr && !ret; ++i) {
        ret = Move_point(arr[i], act);
    }
    return ret;
}

int Draw_line(My_Scene &scene, const Point &a, const Point &b) {

    return Draw_2d_line(scene, a.x, a.y, b.x, b.y);
}
