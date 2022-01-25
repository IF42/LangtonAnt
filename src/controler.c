#include "controler.h"



bool
controler_ant_step(Model * model)
{
    if(model_ant_in_bounds(model) == true)
    {
        if(model->formicarium
            [model->antPosition.x]
            [model->antPosition.y] == CeelWhite)
        {
            model->formicarium
                [model->antPosition.x]
                [model->antPosition.y] = 
                    CeelBlue;

            switch(model->direction)
            {
                case North:
                    model->direction = East;
                    model->antPosition.x++;
                    break;
                case East:
                    model->direction = South;
                    model->antPosition.y++;
                    break;
                case South:
                    model->direction = West;
                    model->antPosition.x--;
                    break;
                case West:
                    model->direction = North;
                    model->antPosition.y--;
                    break;
            }
        }
        else
        {
            model->formicarium
                [model->antPosition.x]
                [model->antPosition.y] = 
                    CeelWhite;

            switch(model->direction)
            {
                case North:
                    model->direction = West;
                    model->antPosition.x--;
                    break;
                case East:
                    model->direction = North;
                    model->antPosition.y--;
                    break;
                case South:
                    model->direction = East;
                    model->antPosition.x++;
                    break;
                case West:
                    model->direction = South;
                    model->antPosition.y++;
                    break;
            }
        }

        return true;
    }

    return false;
}



