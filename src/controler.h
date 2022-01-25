#ifndef _CONTROLER_H_
#define _CONTROLER_H_

#include <stdbool.h>
#include "model.h"


/*
** Function for update ant position/state based on its current state
*/
bool
controler_ant_step(Model * model);

#endif
