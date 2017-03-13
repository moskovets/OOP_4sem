#include "model_action.h"

#include "point_arr.h"
#include "edges.h"

#include "errors.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "draw_on_scene.h"
Model Init_model() {
    Model model;
    model.vertex = Init_vertex();
    model.edges = Init_edges();
    return model;
}

int Rotate_model(Model &model, const Rotate &act) {
    return Rotate_point_arr(model.vertex, act);
}

int Scale_model(Model &model, const Scale &act) {
    return Scale_point_arr(model.vertex, act);
}

int  Move_model(Model &model, const Move &act) {
    return Move_point_arr(model.vertex, act);
}
int SaveModel(const Model &model, const Create &act) {
    std::ofstream out;
    out.open(act.fileName);
    if(!out) {
        return FILE_NOT_FIND;
    }
    int ret = 0;

    ret = Save_point_arr(model.vertex, out);
    if(!ret)
        ret = Save_edge_arr(model.edges, out);

    out.close();
    return ret;

}


int LoadModel(Model &model, const Create &act) {
    std::ifstream inp;
    inp.open(act.fileName);
    if(!inp) {
        return FILE_NOT_FIND;
    }
    Model buff;
    int ret = 0;
    ret = Load_point_arr(buff.vertex, inp);
    if(!ret)
        ret = Load_edge_arr(buff.edges, inp);
    if(!ret)
        ret = Free_model(model);
    if(!ret)
        model = buff;
    inp.close();
    return ret;
}

int Free_model(Model &model) {
    Free_Edge_arr(model.edges);
    Free_Point_arr(model.vertex);
    return 0;
}


int Draw_model(My_Scene &scene, const Model &model) {
    if(model.vertex.N_v == 0)
        return MODEL_EMPTY;
    Clean_Scene(scene);
    int res;
    for(int i = 0; i < model.edges.N_e; i++) {
        //Get_vertex_number(j, k, model.edges, i);
        res = Draw_line(scene, model.vertex.arr[model.edges.arr[i][0]], model.vertex.arr[model.edges.arr[i][1]]);
        if(res != 0) {
            return res;
        }
    }
    return 0;
}

