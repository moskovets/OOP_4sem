#include "edges.h"
#include "errors.h"
#include "stdio.h"

#define BUFF_SIZE 100
edges_arr Init_edges()
{
    edges_arr edges;
    edges.arr = NULL;
    edges.N_e = 0;
    return edges;
}

int Load_edge_arr(edges_arr &edges, IN_Stream &stream)
{
    int N;
    int ret = 0;
    ret = Read_Stream(N, stream);
    if(ret) {
        return ret;
    }
    edges.N_e = N;
    ret = Allocate_Edge_arr(edges);

    for(int i = 0; i < N && !ret; i++) {
        ret = Load_edge(edges.arr[i], stream);
    }
    if(ret) {
        Free_Edge_arr(edges);
    }
    return ret;
}
int Load_edge(t_edge& p, IN_Stream &stream)
{
    int x, y;
    int ret = Read_Stream(x, stream);
    if(!ret)
        ret = Read_Stream(y, stream);

    if(!ret) {
        p[0] = x - 1;
        p[1] = y - 1;
    }
    return ret;
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

int Save_edge_arr(const edges_arr &edges, OUT_Stream &stream) {
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%d\n", edges.N_e);
    int ret = Print_Stream(stream, buff);

    for(int i = 0; i < edges.N_e && !ret; i++) {
        ret = Save_edge(edges.arr[i], stream);
    }
    return ret;
}

int Save_edge(const t_edge& p, OUT_Stream &stream) {
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%d %d\n", p[0]+1, p[1]+1);
    return Print_Stream(stream, buff);
}

int Get_N_edges(const edges_arr & edges) {
    return edges.N_e;
}

int Get_edge_start(const edges_arr &edges, int i) {
    return edges.arr[i][0];
}

int Get_edge_end(const edges_arr &edges, int i) {
    return edges.arr[i][1];
}

t_edge* Get_edges_arr(const edges_arr &edges) {
    return edges.arr;
}
