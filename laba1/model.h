#ifndef MODEL_H
#define MODEL_H
#include "point_arr.h"
#include "edges.h"
#include <stdlib.h>

struct Model {
    //vertex_arr vertexes;
    Point *vertex = NULL;
    int N_v = 0;
    edges_arr edges;
};

#endif // MODEL_H
