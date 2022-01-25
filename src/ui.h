#ifndef _UI_H_
#define _UI_H_

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdbool.h>

#define UI_TYPE_WIDGET (ui_widget_get_type())


/*
** Shortcut macro for getting GtkDrawingArea widget from UiWidget
*/
#define UI_WIDGET_DRAWING(widget)\
    (ui_widget_drawing(UI_WIDGET(widget)))

struct _UiWidget;


/*
** GtkWidget class deriving for UiWidget definition
*/
G_DECLARE_FINAL_TYPE(
    UiWidget
    , ui_widget
    , UI
    , WIDGET
    , GtkWindow)


/*
** Constructor for UiWidget
*/
GtkWidget *
ui_widget_new(GtkApplication * application);


/*
** Getter function for GtkDrawingArea widget from UiWidget
*/
GtkWidget *
ui_widget_drawing(UiWidget * ui);


#endif
