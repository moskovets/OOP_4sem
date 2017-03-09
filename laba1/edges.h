#ifndef EDGES_H
#define EDGES_H
#include <fstream>

typedef int t_edge[2];

int Load_edge_arr(std::ifstream &inp, t_edge** arr, int &N);
int Load_edge(std::ifstream &inp, t_edge& p);
int Allocate_Edge_arr(t_edge **arr, const int N);
int Free_Edge_arr(t_edge** arr);

int Save_edge_arr(std::ofstream &out, const t_edge* arr, const int N);
int Save_edge(std::ofstream &out, const t_edge& p);

#endif // EDGES_H
