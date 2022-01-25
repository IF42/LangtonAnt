#include "ui.h"



struct _UiWidget
{
    GtkWindow window;
    GtkWidget * drawArea;
};


G_DEFINE_TYPE (
    UiWidget
    , ui_widget
    , GTK_TYPE_WINDOW)


static void
ui_widget_init (UiWidget * widget);


static void
ui_widget_class_init (UiWidgetClass * class);


static void
ui_widget_build(UiWidget * widget);


static void
ui_widget_pack(UiWidget * widget);


static void
ui_widget_setup(UiWidget * widget);


static void
ui_widget_signals(UiWidget * widget);


GtkWidget *
ui_widget_new(GtkApplication * application)
{
	GtkWidget * widget = 
        GTK_WIDGET (
            g_object_new (
                UI_TYPE_WIDGET
                , "application"
                , application
                , NULL));

    ui_widget_build(UI_WIDGET(widget));
    ui_widget_pack(UI_WIDGET(widget));
    ui_widget_signals(UI_WIDGET(widget));
    ui_widget_setup(UI_WIDGET(widget));

	return widget;
}


GtkWidget *
ui_widget_drawing(UiWidget * ui)
{
    return ui->drawArea;
}


static void
ui_widget_build(UiWidget * widget)
{
    widget->drawArea = gtk_drawing_area_new();
}


static void
ui_widget_pack(UiWidget * widget)
{
    gtk_window_set_child(
        GTK_WINDOW(widget)
        , widget->drawArea);
}

static void
ui_widget_setup(UiWidget * widget)
{
    gtk_window_set_default_size(
        GTK_WINDOW(widget)
        , 800
        , 600);
    gtk_window_maximize(GTK_WINDOW(widget));
}

static void
ui_widget_signals(UiWidget * widget)
{

}

static void
ui_widget_init (UiWidget * widget)
{

}


static void
ui_widget_class_init (UiWidgetClass * class)
{

}






