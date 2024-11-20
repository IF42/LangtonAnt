#include "formicarium.h"

#include <stdlib.h>


Formicarium formicarium_init (bool init_seed, size_t width, size_t height) {
    Formicarium instance = {
        .width = width
        , .height = height
        , .array = malloc(sizeof(CellState) * width * height)
    };

    /*
     * Initialization function for formicarium with random settings some cells into blue
     */
    if(init_seed  == true) {
        for(size_t i = 0; i < width; i ++) {
            for(size_t j = 0; j < height; j ++) {
                if(i > (width / 2) - 5 && i < (width / 2) + 5 && j > (height / 2) - 5 && j < (height / 2) + 5) {
                    formicarium_at(&instance, i, j) = rand() % (CeelBlue + 1);
                } else {
                    formicarium_at(&instance, i, j) = CeelWhite;
                }
            }
        }
    }
    
    return instance;
}


void formicarium_finalize(Formicarium * self) {
    if(self->array != NULL) {
        free(self->array);
    }
}

