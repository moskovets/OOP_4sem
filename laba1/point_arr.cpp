#include "point_arr.h"
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
