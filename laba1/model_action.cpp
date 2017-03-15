#include "model_action.h"

#include "point_arr.h"
#include "edges.h"

#include "errors.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include "draw_on_scene.h"

int LoadModel(Model &model, IN_Stream &stream);

Model Init_model() {
    Model model;
    model.vertex = Init_vertex();
    model.edges = Init_edges();
    return model;
}

int Is_init_model(const Model &model) {
    return Get_N_vertex(model);
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
    OUT_Stream stream;
    int ret = Open_Stream(stream, act.fileName);
    if(ret)
        return ret;
    ret = Save_point_arr(model.vertex, stream);
    if(!ret)
        ret = Save_edge_arr(model.edges, stream);
    Close_Stream(stream);
    return ret;

}
int LoadModel(Model &model, IN_Stream &stream) {
    int ret = Load_point_arr(model.vertex, stream);
    if(!ret)
        ret = Load_edge_arr(model.edges, stream);
    return ret;
}

int LoadModel(Model &model, const Create &act) {
    IN_Stream stream;
    int ret = Open_Stream(stream, act.fileName);
    if(ret)
        return ret;
    Model buff;
    ret = LoadModel(buff, stream);
    if(!ret)
        ret = Free_model(model);
    if(!ret)
        model = buff;
    Close_Stream(stream);
    return ret;
}

int Free_model(Model &model) {
    Free_Edge_arr(model.edges);
    Free_Point_arr(model.vertex);
    return 0;
}


int Draw_model(My_Scene &scene, const Model &model) {
    int N_e = Get_N_edges(model);
    if(Is_init_model(model))
        return MODEL_EMPTY;
    Clean_Scene(scene);

    int ret = 0;
    for(int i = 0; i < N_e && !ret; i++) {
        int start = Get_edge_start(model.edges, i);
        int end = Get_edge_end(model.edges, i);
        Point p1 = Get_Point(model.vertex, start);
        Point p2 = Get_Point(model.vertex, end);
        ret = Draw_line(scene, p1, p2);
    }
    return ret;
}

int Get_N_vertex(const Model &model) {
    return Get_N_vertex(model.vertex);
}

int Get_N_edges(const Model &model) {
    return Get_N_edges(model.edges);
}

vertex_arr Get_vertex_arr(const Model &model) {
    return model.vertex;
}
/*Point* Get_vertex_arr(const Model &model) {
    return Get_vertex_arr(model.vertex);
}*/
edges_arr Get_edges_arr(const Model &model) {
    return model.edges;
}
/*t_edge* Get_edges_arr(const Model &model) {
    return Get_edges_arr(model.edges);
}*/
