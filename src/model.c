#include "model.h"


AppModel model_init(Formicarium formicarium) {
    return (AppModel) {
        .formicarium = formicarium
        , .ant = {
            .x = formicarium.width/2
            , .y = formicarium.height/2
            , .orientation = Ant_Orientation_North
        }
    };
}


bool model_ant_in_bounds(AppModel * model) {
    if(model->ant.x < (model->formicarium.width) 
            && model->ant.y < (model->formicarium.height)) {
        return true;
    } else {
        return false;
    }
}   


