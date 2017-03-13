#ifndef MODEL_H
#define MODEL_H
#include "point_arr.h"
#include "edges.h"
#include <stdlib.h>

struct Model {
    vertex_arr vertex;
    edges_arr edges;
};

#endif // MODEL_H
