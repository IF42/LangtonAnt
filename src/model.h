#ifndef _MODEL_H_
#define _MODEL_H_

#include "formicarium.h"

#include <stdlib.h>
#include <stdbool.h>


/*
 * Orientation for ant in formicarium field
 */
typedef enum {
    Ant_Orientation_North
    , Ant_Orientation_East
    , Ant_Orientation_South
    , Ant_Orientation_West
} Ant_Orientation;


/*
 * Ant defined as position
 */
typedef struct {
    size_t x;
    size_t y;
    Ant_Orientation orientation;
} Ant;


/*
 * AppModel structure work as global state of application
 */
typedef struct  {
   Formicarium formicarium;
   Ant ant;
} AppModel;


/*
 * Constructor for AppModel data type
 */
AppModel model_init(Formicarium formicarium);


/*
 * Function whitch retururns information if the ant is in 
 * bounds of formicarium field 
 */
bool model_ant_in_bounds(AppModel * model);


#endif


