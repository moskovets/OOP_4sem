#ifndef WORK_H
#define WORK_H

#include "action.h"
#include "model.h"

enum type_action { ROTATE, CREATE, MOVE, SCALE, FREE, SAVE };
union t_action {
    Rotate rotat;
    Scale scal;
    Create creat;
    Move mov;
    bool free;
};

int main_controller(Model &model, const t_action &act, type_action t);

#endif // WORK_H
