#include "controller.h"


bool controler_ant_step(AppModel * model) {
    if(model_ant_in_bounds(model) == true) {
        if(formicarium_at(&model->formicarium, model->ant.x, model->ant.y) == CeelWhite) {
            formicarium_at(&model->formicarium, model->ant.x, model->ant.y) = CeelBlue;

            switch(model->ant.orientation) {
                case Ant_Orientation_North:
                    model->ant.orientation = Ant_Orientation_East;
                    model->ant.x++;
                    break;
                case Ant_Orientation_East:
                    model->ant.orientation = Ant_Orientation_South;
                    model->ant.y++;
                    break;
                case Ant_Orientation_South:
                    model->ant.orientation = Ant_Orientation_West;
                    model->ant.x--;
                    break;
                case Ant_Orientation_West:
                    model->ant.orientation = Ant_Orientation_North;
                    model->ant.y--;
                    break;
            }
        } else {
            formicarium_at(&model->formicarium, model->ant.x, model->ant.y) = CeelWhite;

            switch(model->ant.orientation) {
                case Ant_Orientation_North:
                    model->ant.orientation = Ant_Orientation_West;
                    model->ant.x--;
                    break;
                case Ant_Orientation_East:
                    model->ant.orientation = Ant_Orientation_North;
                    model->ant.y--;
                    break;
                case Ant_Orientation_South:
                    model->ant.orientation = Ant_Orientation_East;
                    model->ant.x++;
                    break;
                case Ant_Orientation_West:
                    model->ant.orientation = Ant_Orientation_South;
                    model->ant.y++;
                    break;
            }
        }

        return true;
    }

    return false;
}



