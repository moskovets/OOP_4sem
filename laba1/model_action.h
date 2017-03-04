#ifndef MODEL_ACTION_H
#define MODEL_ACTION_H

#include "action.h"
#include "model.h"

void Rotate_model(Model &model, Rotate &act);
void Scale_model(Model &model, Scale &act);
void Move_model(Model &model, Move &act);

int DounloadModel(Model &model, Create &act);

void Free_model(Model &model);
int Create_model(Model &model, const int N_v, const int N_e);
#endif // MODEL_ACTION_H
