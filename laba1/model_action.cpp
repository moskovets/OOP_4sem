#include "model_action.h"

#include "point.h"
#include <stdlib.h>
void Rotate_model(Model &model, const Rotate &act) {
    Rotate_point_arr(model.vertex, model.N_v, act);
}

void Scale_model(Model &model, const Scale &act) {
    Scale_point_arr(model.vertex, model.N_v, act);
}

void Move_model(Model &model, const Move &act) {
    Move_point_arr(model.vertex, model.N_v, act);
}

int DownloadModel(Model &model, const Create &act) {
    //TODO
}

void Free_model(Model &model) {
    if(model.edge)
        delete[] model.edge;
    if(model.vertex)
        delete[] model.vertex;
}

int Create_model(Model &model, const int N_v, const int N_e) {
    model.vertex = new Point[N_v];
    if(!model.vertex)
        return 1;
    model.edge = new int[N_e][2];
    if(!model.edge) {
        delete[] model.vertex;
        return 1;
    }
    return 0;
}
