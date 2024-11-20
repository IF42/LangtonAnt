#include "formicarium.h"

#include <stdlib.h>


Formicarium formicarium_init (size_t width, size_t height) {
    Formicarium instance = {
        .width = width
        , .height = height
        , .array = malloc(sizeof(CellState) * width * height)
    };

    /*
     * Initialization function for formicarium with random settings some cells into blue
     */
    for(size_t i = 0; i < width; i ++) {
        for(size_t j = 0; j < height; j ++) {
            if(i > (width / 2) - 10 && i < (width / 2) + 10 && j > (height / 2) - 10 && j < (height / 2) + 10) {
                formicarium_at(&instance, i, j) = rand() % (CeelBlue + 1);
            } else {
                formicarium_at(&instance, i, j) = CeelWhite;
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

