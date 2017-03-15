#include "point_arr.h"
#include "errors.h"

vertex_arr Init_vertex() {
    vertex_arr vertex;
    vertex.arr = NULL;
    vertex.N_v = 0;
    return vertex;
}

int Load_point_arr(vertex_arr &vertex, IN_Stream &stream)
{
    int N;
    int ret = 0;
    ret = Read_Stream(N, stream);
    if(ret) {
        return ret;
    }
    vertex.N_v = N;
    ret = Allocate_Point_arr(vertex);

    for(int i = 0; i < N && !ret; i++) {
        ret = Load_point(vertex.arr[i], stream);
    }
    if(ret) {
        Free_Point_arr(vertex);
    }
    return ret;
}

int Allocate_Point_arr(vertex_arr &vertex) {
    vertex.arr = new Point [vertex.N_v];
    if(!(vertex.arr))
        return MEMORY_ERROR;
    return 0;
}
int Free_Point_arr(vertex_arr &vertex) {
    if(vertex.arr)
        delete[] vertex.arr;
    vertex.arr = NULL;
    vertex.N_v = 0;
    return 0;
}
int Save_point_arr(const vertex_arr &vertex, OUT_Stream &stream)
{
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%d\n", vertex.N_v);
    int ret = Print_Stream(stream, buff);

    for(int i = 0; i < vertex.N_v && !ret; i++) {
        ret = Save_point(vertex.arr[i], stream);
    }
    return ret;
}

int Rotate_point_arr(vertex_arr &vertex, const Rotate &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;
    t_matrix m;
    GetResultMatrix(m, act);
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = Change_Point_with_matrix(vertex.arr[i], m);
    }
   return ret;
}
int Scale_point_arr(vertex_arr &vertex, const Scale &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;

    t_matrix m;
    GetResultMatrix(m, act);
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = Change_Point_with_matrix(vertex.arr[i], m);
    }
    return ret;
}

int Move_point_arr(vertex_arr &vertex, const Move &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;

    t_matrix m;
    GetResultMatrix(m, act);
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = Change_Point_with_matrix(vertex.arr[i], m);
    }
    return ret;
}

int Get_N_vertex(const vertex_arr &vertex) {
    return vertex.N_v;
}

Point Get_Point(const vertex_arr &vertex, int i) {
    return vertex.arr[i];
}
Point* Get_vertex_arr(const vertex_arr &vertex) {
    return vertex.arr;
}

