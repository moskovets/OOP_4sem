#include "point.h"
#include "draw_on_scene.h"
#include "errors.h"
#include "stdio.h"

#define BUFF_SIZE 100

int Load_point(Point& p, IN_Stream &stream)
{
    double x, y, z;
    int ret = 0;
    ret = Read_Stream(x, stream);
    if(!ret)
        ret = Read_Stream(y, stream);
    if(!ret)
        ret = Read_Stream(z, stream);

    if(!ret) {
        p.x = x;
        p.y = y;
        p.z = z;
    }
    return ret;
}


int Save_point(const Point& p, OUT_Stream &stream)
{
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%f %f %f\n", p.x, p.y, p.z);
    return Print_Stream(stream, buff);
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
void Copy_matrix(t_matrix res, const t_matrix a)
{
    for(int i = 0; i < N_DIMEN; i++) {
        for(int j = 0; j < N_DIMEN; j++) {
            res[i][j] = a[i][j];
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
void GetResultMatrix(t_matrix a, const Scale &act) {
    t_matrix m = { { act.kx, 0, 0 },
                   { 0, act.ky, 0 },
                   { 0, 0, act.kz } };
    Copy_matrix(a, m);
}

void GetResultMatrix(t_matrix a, const Move &act) {
    t_matrix m = { { 1, 0, 0, act.dx },
                   { 0, 1, 0, act.dy },
                   { 0, 0, 1, act.dz },
                   { 0, 0, 0, 1 } };
    Copy_matrix(a, m);
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
    vec[3] = 1;
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

int Draw_line(My_Scene &scene, const Point &a, const Point &b) {

    return Draw_2d_line(scene, a.x, a.y, b.x, b.y);
}
