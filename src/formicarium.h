#ifndef _FORMICARIUM_H_
#define _FORMICARIUM_H_

#include <stdbool.h>
#include <stddef.h>

/*
 * Enum for cell color types
 */
typedef enum {
    CeelWhite = 0
    , CeelBlue
    , CeelRed
    , CeelAnt
} CellState;


/*
 * alias for two-dimensional array of CellState as Formicarium 
 */
typedef struct {
    size_t width;
    size_t height;
    CellState * array;
} Formicarium;


/*
 *
 */
Formicarium formicarium_init (bool init_seed, size_t width, size_t height);


/*
 *
 */
#define formicarium_at(T, i, j) (T)->array[((T)->width * (j)) + (i)]


/*
 * 
 */
void formicarium_finalize(Formicarium * self);


#endif



