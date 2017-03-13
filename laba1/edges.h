#ifndef EDGES_H
#define EDGES_H
#include "my_stream.h"

typedef int t_edge[2];

struct edges_arr {
    t_edge *arr = NULL;
    int N_e = 0;
};

edges_arr Init_edges();

int Load_edge_arr(edges_arr &edges, IN_Stream &stream);
int Load_edge(t_edge& p, IN_Stream &stream);
int Allocate_Edge_arr(edges_arr &edges);
int Free_Edge_arr(edges_arr &edges);

int Save_edge_arr(const edges_arr &edges, OUT_Stream &stream);
int Save_edge(const t_edge& p, OUT_Stream &stream);

int Get_N_edges(const edges_arr & edges);

int Get_edge_start(const edges_arr &edges, int i);
int Get_edge_end(const edges_arr &edges, int i);

#endif // EDGES_H
