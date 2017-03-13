#include "point_arr.h"
#include "errors.h"

vertex_arr Init_vertex() {
    vertex_arr vertex;
    vertex.arr = NULL;
    vertex.N_v = 0;
    return vertex;
}

int Load_point_arr(vertex_arr &vertex, std::ifstream &inp)
{
    int N;
    if(!(inp >> N)) {
        return FILE_ERROR;
    }
    vertex.N_v = N;
    int ret = 0;
    ret = Allocate_Point_arr(vertex);

    for(int i = 0; i < N && !ret; i++) {
        ret = Load_point(inp, vertex.arr[i]);
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
int Save_point_arr(const vertex_arr &vertex, std::ofstream &out)
{
    if(!out)
        return FILE_NOT_FIND;
    out << vertex.N_v << std::endl;
    for(int i = 0; i < vertex.N_v; i++) {
        Save_point(out, vertex.arr[i]);
    }
    return 0;
}

int Rotate_point_arr(vertex_arr &vertex, const Rotate &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;
    t_matrix m;
    int ret = 0;
    GetResultMatrix(m, act);
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = Change_Point_with_matrix(vertex.arr[i], m);
    }
   return ret;
}
int Scale_point_arr(vertex_arr &vertex, const Scale &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;

    t_matrix m = { { act.kx, 0, 0 },
                   { 0, act.ky, 0 },
                   { 0, 0, act.kz } };
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
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = Move_point(vertex.arr[i], act);
    }
    return ret;
}
