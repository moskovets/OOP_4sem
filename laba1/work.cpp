#include "work.h"

#include "model.h"
#include "model_action.h"
//#include <iostream>

int main_controller(My_Scene &scene, const t_action &act, type_action t)
{
    static Model model; //INIT?

    int result = OK;
    switch(t) {
    case CREATE:
        result = DownloadModel(model, act.creat);
        break;
    case ROTATE:
        result = Rotate_model(model, act.rotat);
        break;
    case SCALE:
        result = Scale_model(model, act.scal);
        break;
    case MOVE:
        result = Move_model(model, act.mov);
        break;
    case FREE:
        result = Free_model(model);
        break;
    case SAVE:
        result = SaveModel(model, act.creat);
        break;
    case DRAW:
        result = Draw_model(scene, model);
        break;
    default:
        result = -1;
    }
    return result;
}

