#include "view.h"
#include "controler.h"
#include "model.h"

#include <assert.h>

/*
** Helper structure for easier communication betwen widgets
*/
typedef struct
{
    GtkWidget * ui;
    Model     * model;
    bool        run;
}View;


/*
** Function where are setup local signals and callbacks from widgets
*/
static void 
view_signals(View * view);


/*
** Function where is setup state of View module
*/
static void
view_setup(View * view);


/*
** Drawing callback for drawing ant to the window
*/
static void
view_draw_callback (
    GtkDrawingArea * area
    , cairo_t * cr
    , int width
    , int height
    , gpointer param);


/*
** Cyclic interupt function where is called request for repaint of the window
*/
static gboolean
view_cyclic_interupt(View * view);


/*
** Finalizer of the View module
*/
static void 
view_finalize(
    GtkWidget * widget
    , gpointer param);


/*
** Global instance of View structure for easier communication between widgets
*/
static View view;


void 
view_activate_callback(
    GtkApplication * application
    , gpointer param)
{
    view = (View) 
       {.ui     = ui_widget_new(application)
       , .model = (Model*) param
       , .run   = true};

    assert(view.model != NULL);
    assert(view.ui != NULL);

    view_signals(&view);
    view_setup(&view);
}


static void 
view_signals(View * view)
{
    g_signal_connect(
        G_OBJECT(UI_WIDGET_DRAWING(view->ui))
        , "destroy", 
        G_CALLBACK(view_finalize), view); 

    gtk_drawing_area_set_draw_func(
        GTK_DRAWING_AREA(UI_WIDGET_DRAWING(view->ui))
        , view_draw_callback
        , view->model
        , NULL);

    g_timeout_add(
        1
        , (GSourceFunc) view_cyclic_interupt
        , view);
}


static gboolean
view_cyclic_interupt(View * view)
{
    if(controler_ant_step(view->model)
        && view->run == true)
    {
        gtk_widget_queue_draw(UI_WIDGET_DRAWING(view->ui));
        return true;
    }

    return false;
}


static void
view_setup(View * view)
{
    gtk_widget_show(view->ui);
}


static void
view_draw_callback (
    GtkDrawingArea *area
    , cairo_t * cr
    , int width
    , int height
    , gpointer param)
{
    Model * model = param;

    double rectangle_width = 
        ((double) width) / ((double) model->formicariumSize.x);
    double rectangle_height = 
        ((double) height) / ((double) model->formicariumSize.y);

    for(int i = 0; i < model->formicariumSize.x; i++)
    {
        for(int j = 0; j < model->formicariumSize.y; j++)
        {
            switch (model->formicarium[i][j])
            {
                case CeelBlue:
                    cairo_set_source_rgb(cr, 0, 0, 0.9);
                    break;
                case CeelRed:
                    cairo_set_source_rgb(cr, 0.9, 0, 0);  
                    break;
                case CeelWhite:
                    cairo_set_source_rgb(cr, 0.9, 0.9, 0.9); 
                    break;
                case CeelAnt:  
                    cairo_set_source_rgb(cr, 0.1, 0.1, 0.1); 
                    break;
            }

            cairo_rectangle(
                cr
                , i * rectangle_width
                , j * rectangle_height
                , rectangle_width
                , rectangle_height);

            cairo_fill (cr);
        }
    }
}


static void 
view_finalize(
    GtkWidget * widget
    , gpointer param)
{
    if(param != NULL)
        ((View*) param)->run = false;
}
