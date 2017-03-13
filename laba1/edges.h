#ifndef EDGES_H
#define EDGES_H
#include <fstream>

typedef int t_edge[2];

struct edges_arr {
    t_edge *arr = NULL;
    int N_e = 0;
};

edges_arr Init_edges();

int Load_edge_arr(edges_arr &edges, std::ifstream &inp);
int Load_edge(t_edge& p, std::ifstream &inp);
int Allocate_Edge_arr(edges_arr &edges);
int Free_Edge_arr(edges_arr &edges);

int Save_edge_arr(const edges_arr &edges, std::ofstream &out);
int Save_edge(const t_edge& p, std::ofstream &out);

#endif // EDGES_H
