#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <raylib.h>

#include <model.h>
#include <controller.h>
#include <formicarium.h>


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main(void) {
    srand(time(NULL));
    Formicarium formicarium = formicarium_init(WINDOW_WIDTH/10, WINDOW_HEIGHT/10);
    AppModel model = model_init(formicarium);

    /*
     * window setup
     */
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Langton's ant");
    SetTargetFPS(200);

    float rect_width = ((float) WINDOW_WIDTH) / ((float) model.formicarium.width);
    float rect_height = ((float) WINDOW_HEIGHT) / ((float) model.formicarium.height);
    bool ant_alive = true;
    /*
     * game loop
     */
    while(WindowShouldClose() == false) {
		if(ant_alive == true) {
			ant_alive = controler_ant_step(&model);
		}

        /*
         * window content drawing
         */
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        
        for(size_t i = 0; i < model.formicarium.width; i++) {
            for(size_t j = 0; j < model.formicarium.height; j++) {
                switch (formicarium_at(&model.formicarium, i, j)) {
                    case CeelBlue:
                        DrawRectangle(i*10, j*10, rect_width, rect_height, BLUE);
                        break;
                    case CeelRed:
                        DrawRectangle(i*10, j*10, rect_width, rect_height, RED);
                        break;
                    case CeelWhite:
                        DrawRectangle(i*10, j*10, rect_width, rect_height, LIGHTGRAY);
                        break;
                    case CeelAnt:  
                        DrawRectangle(i*10, j*10, rect_width, rect_height, BLACK);
                        break;
                }
            }
        }

        EndDrawing();
    }

    /*
     * clear environment
     */
    CloseWindow();
    formicarium_finalize(&formicarium);

    return EXIT_SUCCESS;
}

