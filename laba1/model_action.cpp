#include "model_action.h"

#include "point.h"
#include "edges.h"

#include "errors.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "draw_on_scene.h"
int Copy_model(Model &model, const Model &copy);

int Rotate_model(Model &model, const Rotate &act) {
    return Rotate_point_arr(model.vertex, model.N_v, act);
}

int Scale_model(Model &model, const Scale &act) {
    return Scale_point_arr(model.vertex, model.N_v, act);
}

int  Move_model(Model &model, const Move &act) {
    return Move_point_arr(model.vertex, model.N_v, act);
}
int SaveModel(const Model &model, const Create &act) {
    std::ofstream out;
    out.open(act.fileName);
    if(!out) {
        return FILE_NOT_FIND;
    }
    int ret = 0;

    ret = Save_point_arr(out, model.vertex, model.N_v);
    if(!ret)
        ret = Save_edge_arr(out, model.edge, model.N_e);

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
    ret = Load_point_arr(inp, &buff.vertex, buff.N_v);
    if(!ret)
        ret = Load_edge_arr(inp, &buff.edge, buff.N_e);
    if(!ret)
        ret = Free_model(model);
    if(!ret)
        model = buff;
    inp.close();
    return ret;
}

int Free_model(Model &model) {
    model.N_e = 0;
    model.N_v = 0;
    Free_Edge_arr(&model.edge);
    Free_Point_arr(&model.vertex);
    return 0;
}

/*int Create_model(Model &model, const int N_v, const int N_e) {
    model.vertex = new Point[N_v];
    if(!model.vertex)
        return 1;
    model.edge = new int[N_e][2];
    if(!model.edge) {
        delete[] model.vertex;
        return 1;
    }
    return 0;
}*/

int Draw_model(My_Scene &scene, const Model &model) {
    if(model.N_v == 0)
        return MODEL_EMPTY;
    Clean_Scene(scene);
    int res;
    for(int i = 0; i < model.N_e; i++) {
        res = Draw_line(scene, model.vertex[model.edge[i][0]], model.vertex[model.edge[i][1]]);
        if(res != 0) {
            return res;
        }
    }
    return 0;
}

