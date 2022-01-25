#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/view.h"
#include "../src/model.h"

int 
main(int argc, char ** argv)
{
    GtkApplication * application = 
        gtk_application_new(
            "edit.me.langton"
            , G_APPLICATION_FLAGS_NONE);
    
    Model * model = model_new(100, 100);

    g_signal_connect(
        application
        , "activate"
        , G_CALLBACK(view_activate_callback)
        , model);

    int result = 
        g_application_run(
            G_APPLICATION(application)
            , argc
            , argv);

    g_object_unref(application);    
    model_finalize(model);    

    return result;
}

