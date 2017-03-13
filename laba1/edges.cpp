#include "edges.h"
#include "errors.h"

edges_arr Init_edges()
{
    edges_arr edges;
    edges.arr = NULL;
    edges.N_e = 0;
    return edges;
}

int Load_edge_arr(edges_arr &edges, std::ifstream &inp)
{
    int N;
    if(!(inp >> N)) {
        return FILE_ERROR;
    }
    edges.N_e = N;
    int ret = 0;
    ret = Allocate_Edge_arr(edges);

    for(int i = 0; i < N && !ret; i++) {
        ret = Load_edge(edges.arr[i], inp);
    }
    if(ret) {
        Free_Edge_arr(edges);
    }
    return ret;
}
int Load_edge(t_edge& p, std::ifstream &inp)
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

int Allocate_Edge_arr(edges_arr &edges)
{
    edges.arr = new t_edge [edges.N_e];
    if(!(edges.arr))
        return MEMORY_ERROR;
    return 0;
}

int Free_Edge_arr(edges_arr &edges)
{
    if(edges.arr)
        delete[] edges.arr;
    edges.arr = NULL;
    edges.N_e = 0;
    return 0;
}

int Save_edge_arr(const edges_arr &edges, std::ofstream &out) {
    if(!out)
        return FILE_NOT_FIND;
    out << edges.N_e << std::endl;
    for(int i = 0; i < edges.N_e; i++) {
        Save_edge(edges.arr[i], out);
    }
    return 0;
}

int Save_edge(const t_edge& p, std::ofstream &out) {
    if(!out)
        return FILE_NOT_FIND;
    out << p[0] + 1 << " " << p[1] + 1 << std::endl;
    return 0;
}
