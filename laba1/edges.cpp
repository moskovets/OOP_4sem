#include "edges.h"
#include "errors.h"


int Load_edge_arr(std::ifstream &inp, t_edge** arr, int &N)
{
    if(!(inp >> N)) {
        return FILE_ERROR;
    }
    int ret = 0;
    ret = Allocate_Edge_arr(arr, N);

    for(int i = 0; i < N && !ret; i++) {
        ret = Load_edge(inp, (*arr)[i]);
        if(ret) {
            Free_Edge_arr(arr);
        }
    }
    return ret;
}
int Load_edge(std::ifstream &inp, t_edge& p)
{
    int x, y;
    if(inp >> x && inp >> y) {
        p[0] = x - 1;
        p[1] = y - 1;
    }
    else {
        return FILE_ERROR;
    }
    return 0;
}

int Allocate_Edge_arr(t_edge **arr, const int N)
{
    *arr = new t_edge [N];
    if(!(*arr))
        return MEMORY_ERROR;
    return 0;
}

int Free_Edge_arr(t_edge** arr)
{
    if(*arr)
        delete[] *arr;
    return 0;
}

int Save_edge_arr(std::ofstream &out, const t_edge* arr, const int N) {
    if(!out)
        return FILE_NOT_FIND;
    out << N << std::endl;
    for(int i = 0; i < N; i++) {
        Save_edge(out, arr[i]);
    }
    return 0;
}

int Save_edge(std::ofstream &out, const t_edge& p) {
    if(!out)
        return FILE_NOT_FIND;
    out << p[0] + 1 << " " << p[1] + 1 << std::endl;
    return 0;
}
