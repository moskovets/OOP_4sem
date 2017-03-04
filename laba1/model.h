#ifndef MODEL_H
#define MODEL_H
#include "point.h"
#include <stdlib.h>

struct Model {
    Point *vertex = NULL;
    int (*edge)[2] = NULL;
    int N_v = 0;
    int N_e = 0;
};

#endif // MODEL_H
