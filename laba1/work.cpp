#include "work.h"

#include "model_action.h"
//#include <iostream>

int main_controller(Model &model, const t_action &act, type_action t)
{
    switch(t) {
    case CREATE:
        return DownloadModel(model, act.creat);
    case ROTATE:
        Rotate_model(model, act.rotat);
        break;
    case SCALE:
        Scale_model(model, act.scal);
        break;
    case MOVE:
        Move_model(model, act.mov);
        break;
    case FREE:
        Free_model(model);
        break;
    default:
        return -1;
    }
    return 0;
}

