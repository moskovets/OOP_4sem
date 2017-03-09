#include "model_action.h"

#include "point.h"
#include "errors.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
int Rotate_model(Model &model, const Rotate &act) {
    Rotate_point_arr(model.vertex, model.N_v, act);
    return 0;
}

int Scale_model(Model &model, const Scale &act) {
    Scale_point_arr(model.vertex, model.N_v, act);
    return 0;
}

int  Move_model(Model &model, const Move &act) {
    Move_point_arr(model.vertex, model.N_v, act);
    return 0;
}
int SaveModel(const Model &model, const Create &act) {
    std::ofstream out;
    out.open(act.fileName);
    if(!out) {
        return FILE_NOT_FIND;
    }

    out << model.N_v << " " << model.N_e << "\n";

    Save_point_arr(out, model.vertex, model.N_v);

    for(int i = 0; i < model.N_e; i++) {
        out << model.edge[i][0] + 1 << " "
            << model.edge[i][1] + 1 << "\n";
    }
    return 0;

}
//int Download_edge_arr(model, )


int DownloadModel(Model &model, const Create &act) {
    Free_model(model);
    std::ifstream inp;
    inp.open(act.fileName);
    if(!inp) {
        return FILE_NOT_FIND;
    }

    int N, M;
    int a, b;
    int flag = 0;

    inp >> N >> M;
    model.N_e = M;
    model.N_v = N;
    int res = Create_model(model, N, M);
    if(res == 1) {
        return MEMORY_ERROR;
    }

    flag = Download_point_arr(inp, model.vertex, N);

    if(flag == 1) {
        Free_model(model);
        return FILE_ERROR;
    }

    for(int i = 0; i < M; i++) {
        if(inp >> a && inp >> b) {
            if(a <= N && b <= N) {
                model.edge[i][0] = a-1;
                model.edge[i][1] = b-1;
            }
            else {
                flag = 1;

            }
        }
        else {
            flag = 1;
        }
    }
    if(flag == 1) {
        Free_model(model);
        return FILE_ERROR;
    }
    return 0;
}

int Free_model(Model &model) {
    model.N_e = 0;
    model.N_v = 0;
    if(model.edge)
        delete[] model.edge;
    if(model.vertex)
        delete[] model.vertex;
    return 0;
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

int Draw_model(My_Scene &scene, const Model &model) {
    if(model.N_v == 0)
        return MODEL_EMPTY;
    int res;
    for(int i = 0; i < model.N_e; i++) {
        res = Draw_line(scene, model.vertex[model.edge[i][0]], model.vertex[model.edge[i][1]]);
        if(res != 0) {
            return res;
        }
    }
    return 0;
}

