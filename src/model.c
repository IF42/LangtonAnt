#include "model.h"


/*
** Contructor for formicarium field and its initialization
*/
static Formicarium
model_build_formicarium(
    int width
    , int height
    , CellState(*f)());


/*
** Initialization function for formicarium, it always return white cell type
** (Whole formicarium will be white)
*/
static CellState 
model_white_cell(
    int x
    , int y);


/*
** Initialization function for formicarium with random settings some cells into blue
*/
static CellState
model_blue_cell(
    int x
    , int y);



Model *
model_new(int width, int height)
{
    Model * model = malloc(sizeof(Model));
    srand(time(NULL));
    
    if(model != NULL)
    {
        model->formicarium = 
            model_build_formicarium(
                width
                , height
                , model_blue_cell);

        model->formicariumSize = 
            (Dimension)
                {.x = width
                , .y = height};

        model->antPosition = 
            (Coordinate) 
                {.x = width/2
                , .y = height/2};

        model->direction = North;
    }

    return model; 
}


static Formicarium
model_build_formicarium(
    int width
    , int height
    , CellState(*f)(int, int))
{
    Formicarium formicarium = malloc(sizeof(CellState *) * width);
    
    for(int i = 0; i < width; i++)
    {
       formicarium[i] = malloc(sizeof(CellState) * height);
           
       for(int j = 0; j < height; j++)
       {
           formicarium[i][j] = f(i, j);
       }
    }

    return formicarium;
}


static CellState 
model_white_cell(int x, int y)
{
    return CeelWhite;
}


static CellState
model_blue_cell(int x, int y)
{
    if(x > 45 
        && x < 55 
        && y > 45 
        && y < 55)
        return rand() % (CeelBlue+1);
    else
        return CeelWhite;
}


bool
model_ant_in_bounds(Model * model)
{
    return model->antPosition.x >= 0 
            && model->antPosition.y >= 0 
            && model->antPosition.x < (model->formicariumSize.x-1) 
            && model->antPosition.y < (model->formicariumSize.y-1);
}   


void
model_finalize(Model * model)
{
    if(model != NULL)
    {
        if(model->formicarium != NULL)
        {
            for(int i = 0; i < model->formicariumSize.x; i++)
            {
                if(model->formicarium[i] != NULL)
                    free(model->formicarium[i]);
            }

            free(model->formicarium);
        }

        free(model);
    }
}

