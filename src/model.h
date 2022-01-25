#ifndef _MODEL_H_
#define _MODEL_H_

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/*
** Enum for cell color types
*/
typedef enum
{
    CeelWhite = 0
    , CeelBlue
    , CeelRed
    , CeelAnt
}CellState;


/*
** Structure for recording coordinates and dimesions
*/
typedef struct
{
    int x;
    int y;
}Dimension, Coordinate;


/*
** Orientation for ant in formicarium field
*/
typedef enum
{
    North
    , East
    , South
    , West
}Compas;


/*
** alias for two-dimensional array of CellState as Formicarium 
*/
typedef CellState ** Formicarium;


/*
** Model structure work as global state of application
*/
typedef struct 
{
   Formicarium formicarium;
   Dimension formicariumSize;
   Coordinate antPosition;
   Compas direction;
}Model;


/*
** Constructor for Model data type
*/
Model *
model_new(int width, int height);


/*
** Function whitch retururns information if the ant is in 
** bounds of formicarium field 
*/
bool
model_ant_in_bounds(Model * model);


/*
** destructor for Model object class
*/
void
model_finalize(Model * model);


#endif
