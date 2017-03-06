#include "model_action.h"

#include "point.h"
#include <fstream>
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
    Create_model(model, N, M);

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
