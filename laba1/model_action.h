#ifndef MODEL_ACTION_H
#define MODEL_ACTION_H

#include "action.h"
#include "model.h"

void Rotate_model(Model &model, const Rotate &act);
void Scale_model(Model &model, const Scale &act);
void Move_model(Model &model, const Move &act);

int DownloadModel(Model &model, const Create &act);

int SaveModel(const Model &model, const Create &act);

void Free_model(Model &model);
int Create_model(Model &model, const int N_v, const int N_e);
#endif // MODEL_ACTION_H
