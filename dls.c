#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include<cairo.h>
#define _BYTE   8
#define _WORD   16
#define _DWORD  32


GtkWidget *and_button, *window, *event_box, *box;
GtkWidget *or_button, *darea, *pack_box, *image;
GtkWidget *not_button; 
GtkWidget *in0_button;
GtkWidget *in1_button;
GtkWidget *out_button;
GtkWidget *wires, *handlebox;
GtkWidget *and_box, *or_box, *not_box, *in0_box, *in1_box, *out_box;
GdkColor color;

	/*	Lines	*/

	/*	drag and drop	*/
/* Define a list of data types called "targets" that a destination widget will
 * accept. The string type is arbitrary, and negotiated between DnD widgets by
 * the developer. An enum or GQuark can serve as the integer target id. */
enum {
        TARGET_INT32,
        TARGET_STRING,
        TARGET_ROOTWIN
};

static GtkTargetEntry target_list[] = {
        { "INTEGER",    0, TARGET_INT32 },
        { "STRING",     0, TARGET_STRING },
        { "text/plain", 0, TARGET_STRING },
        { "application/x-rootwindow-drop", 0, TARGET_ROOTWIN }
};



static guint n_targets = G_N_ELEMENTS(target_list);
static void drag_data_received_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, GtkSelectionData *selection_data, guint target_type, guint time, gpointer data);

/******************************************************************************/
/* Signal receivable by destination */

/* Emitted when the data has been received from the source. It should check
 * the GtkSelectionData sent by the source, and do something with it. Finally
 * it needs to finish the operation by calling gtk_drag_finish, which will emit
 * the "data-delete" signal if told to. */


static void drag_data_received_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, GtkSelectionData *selection_data, guint target_type, guint time, gpointer data){
	glong *_idata;
	gchar *_sdata;

	int dnd_success = 0;
	int delete_selection_data = 0;

	const gchar *name = gtk_widget_get_name(widget);
	g_print("%s: drag_data_received_handl\n", name);

	/*	Dealing with info from source	*/
	if((selection_data != NULL) && (gtk_selection_data_get_length(selection_data) >= 0))
{
		if(gdk_drag_context_get_suggested_action(context) == GDK_ACTION_ASK){
                /* Ask the user to move or copy, then set the context action. */
}

                if (gdk_drag_context_get_suggested_action(context) == GDK_ACTION_MOVE)
                        delete_selection_data = 1;

                /* Check that we got the format we can use */
                g_print (" Receiving ");
                switch (target_type)
                {
                        case TARGET_INT32:
                                _idata = (glong*)gtk_selection_data_get_data(selection_data);
                                g_print ("integer: %ld", *_idata);
                                dnd_success = TRUE;
                                break;
                        case TARGET_STRING:
                                _sdata = (gchar*)gtk_selection_data_get_data(selection_data);
                                g_print ("string: %s", _sdata);
                                dnd_success = TRUE;
                                break;

			default: g_print("NOT FOUND\n");
}
		g_print(".\n");
}

        if (dnd_success == 0)
        {
                g_print ("DnD data transfer failed!\n");
        }

        gtk_drag_finish (context, dnd_success, delete_selection_data, time);

}


	/* Emitted when a drag is over the destination */
static int drag_motion_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint t, gpointer user_data){

        // Fancy stuff here. This signal spams the console something horrible.
        //const gchar *name = gtk_widget_get_name (widget);
        //g_print ("%s: drag_motion_handl\n", name);
        return  0;
}

	/* Emitted when a drag leaves the destination */
static void drag_leave_handl(GtkWidget *widget, GdkDragContext *context, guint time, gpointer user_data){

        const gchar *name = gtk_widget_get_name (widget);
        g_print ("%s: drag_leave_handl\n", name);
}

/* Emitted when the user releases (drops) the selection. It should check that
 * the drop is over a valid part of the widget (if its a complex widget), and
 * itself to return true if the operation should continue. Next choose the
 * target type it wishes to ask the source for. Finally call gtk_drag_get_data
 * which will emit "drag-data-get" on the source. */

static int drag_drop_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint time, gpointer user_data){

        int        is_valid_drop_site;
        GdkAtom         target_type;

        const gchar *name = gtk_widget_get_name (widget);
        g_print ("%s: drag_drop_handl\n", name);

        /* Check to see if (x,y) is a valid drop site within widget */
        is_valid_drop_site = 1;

        /* If the source offers a target */
        if (gdk_drag_context_list_targets (context))
        {
                /* Choose the best target type */
                target_type = GDK_POINTER_TO_ATOM
                        (g_list_nth_data (gdk_drag_context_list_targets(context), TARGET_INT32));

                /* Request the data from the source. */
                gtk_drag_get_data
                (
                        widget,         /* will receive 'drag-data-received' signal */
                        context,        /* represents the current state of the DnD */
                        target_type,    /* the target type we want */
                        time            /* time stamp */
                );
        }
        /* No target offered by source => error */
        else
        {
                is_valid_drop_site = 0;
        }

        return  is_valid_drop_site;
}

/* Emitted when the destination requests data from the source via
 * gtk_drag_get_data. It should attempt to provide its data in the form
 * requested in the target_type passed to it from the destination. If it cannot,
 * it should default to a "safe" type such as a string or text, even if only to
 * print an error. Then use gtk_selection_data_set to put the source data into
 * the allocated selection_data object, which will then be passed to the
 * destination. This will cause "drag-data-received" to be emitted on the
 * destination. GdkSelectionData is based on X's selection mechanism which,
 * via X properties, is only capable of storing data in blocks of 8, 16, or
 * 32 bit units. */
 	
static void drag_data_get_handl(GtkWidget *widget, GdkDragContext *context, GtkSelectionData *selection_data, guint target_type, guint time, gpointer user_data){

        const gchar *name = gtk_widget_get_name (widget);
        const gchar *string_data = "This is data from the source.";
        const glong integer_data = 42;

        g_print ("%s: drag_data_get_handl\n", name);
        g_assert (selection_data != NULL);

        g_print (" Sending ");
        switch (target_type){
        
                /* case TARGET_SOME_OBJECT:
                 * Serialize the object and send as a string of bytes.
                 * Pixbufs, (UTF-8) text, and URIs have their own convenience
                 * setter functions */

        case TARGET_INT32:
                g_print ("integer: %ld", integer_data);
                gtk_selection_data_set
                (
                        selection_data,         /* Allocated GdkSelectionData object */
                        gtk_selection_data_get_target(selection_data), /* target type */
                        _DWORD,                 /* number of bits per 'unit' */
                        (guchar*) &integer_data,/* pointer to data to be sent */
                        sizeof (integer_data)   /* length of data in units */
                );
                break;

        case TARGET_STRING:
                g_print ("string: %s", string_data);
                gtk_selection_data_set
                (
                        selection_data,
                        gtk_selection_data_get_target(selection_data),
                        _BYTE,
                        (guchar*) string_data,
                        strlen (string_data)
                );
                break;

        case TARGET_ROOTWIN:
                g_print ("Dropped on the root window!\n");
                break;


	        default:
        	        /* Default to some a safe target instead of fail. */
        	        g_assert_not_reached ();
        }

        g_print (".\n");
}

	/* Emitted when DnD begins. This is often used to present custom graphics. */
static void drag_begin_handl(GtkWidget *widget, GdkDragContext *context, gpointer user_data){

        const gchar *name = gtk_widget_get_name (widget);
        g_print ("%s: drag_begin_handl\n", name);
}

	/* Emitted when DnD ends. This is used to clean up any leftover data. */
static void drag_end_handl(GtkWidget *widget, GdkDragContext *context, gpointer user_data){

        const gchar *name = gtk_widget_get_name (widget);
        g_print ("%s: drag_end_handl\n", name);
}

void usage();

void draw_wires(GtkWidget *widget, gpointer data){
        gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);
}



static void not_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("not1.png");
        gtk_box_pack_start(GTK_BOX(not_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);

}

static void and_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("and.png");
        gtk_box_pack_start(GTK_BOX(and_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);

}

static void or_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("or.png");
        gtk_box_pack_start(GTK_BOX(or_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);

}

static void in0_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("in0.png");
        gtk_box_pack_start(GTK_BOX(in0_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);

}

static void in1_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("in1.png");
        gtk_box_pack_start(GTK_BOX(in1_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);

}

static void out_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("outbulb.png");
        gtk_box_pack_start(GTK_BOX(out_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);

}

static int delete(GtkWidget *widget, GdkEvent *event,  gpointer data){

	gtk_main_quit();

	return 0;
}

void usage(){
	printf("usage : ./dls\n");
}

int main(int argc, char *argv[]){

	gtk_init(&argc, &argv);

        /*      window  */
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Digital Logic Simulator");
        gtk_window_set_default_size(GTK_WINDOW(window), 1300, 100);

	/*	packing of boxes	*/

	pack_box = gtk_vbox_new(FALSE, 0);
	and_box = gtk_vbox_new(FALSE, 0);
        not_box = gtk_vbox_new(FALSE, 0);
        or_box = gtk_vbox_new(FALSE, 0);
        in0_box = gtk_vbox_new(FALSE, 0);
        in1_box = gtk_vbox_new(FALSE, 0);
        out_box = gtk_vbox_new(FALSE, 0);



	/*	event box	*/
	event_box = gtk_event_box_new();
	gtk_container_add(GTK_CONTAINER(window), pack_box);
	gtk_widget_show(event_box);

        /*      drawing area    */
        darea = gtk_drawing_area_new();
        gtk_container_add(GTK_CONTAINER(event_box), darea);
	gtk_box_pack_start(GTK_BOX(pack_box), event_box, FALSE, FALSE, 0); 

	/*	set background color	*/
	gdk_color_parse("white", &color);
	gtk_widget_modify_bg(window,  GTK_STATE_NORMAL, &color);


        /*      handlebox       */
        handlebox = gtk_handle_box_new();
	gtk_box_pack_start(GTK_BOX(pack_box), handlebox,FALSE, FALSE, 0);

	/*	buttons		*/
	and_button = gtk_button_new_with_label("AND");
        or_button = gtk_button_new_with_label("OR");
        not_button = gtk_button_new_with_label("NOT");
        in0_button = gtk_button_new_with_label("INPUT_0");
        in1_button = gtk_button_new_with_label("INPUT_1");
        out_button = gtk_button_new_with_label("OUPUT");
	wires = gtk_button_new_with_label("WIRES");

	/*	 box	*/
	box = gtk_vbox_new(FALSE, 0);

        gtk_box_pack_start(GTK_BOX(box), and_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), or_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), not_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), in0_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), in1_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), out_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), wires ,TRUE, TRUE, 0);

	gtk_container_add(GTK_CONTAINER(handlebox), box);

	/*	image boxes	*/

	gtk_container_add(GTK_CONTAINER(pack_box), and_box);
        gtk_container_add(GTK_CONTAINER(pack_box), or_box);
        gtk_container_add(GTK_CONTAINER(pack_box), not_box);
        gtk_container_add(GTK_CONTAINER(pack_box), in0_box);
        gtk_container_add(GTK_CONTAINER(pack_box), in1_box);
        gtk_container_add(GTK_CONTAINER(pack_box), out_box);

        /*      closing window  */
        g_signal_connect (window, "delete-event",G_CALLBACK(delete), NULL);

	/*	button event handling	*/
        g_signal_connect(not_button, "clicked", G_CALLBACK(not_dis), NULL);
        g_signal_connect(and_button, "clicked", G_CALLBACK(and_dis), NULL);
        g_signal_connect(or_button, "clicked", G_CALLBACK(or_dis), NULL);
        g_signal_connect(in0_button, "clicked", G_CALLBACK(in0_dis), NULL);
        g_signal_connect(in1_button, "clicked", G_CALLBACK(in1_dis), NULL);
        g_signal_connect(out_button, "clicked", G_CALLBACK(out_dis), NULL);
	g_signal_connect(wires, "clicked", G_CALLBACK(draw_wires), NULL);

	/*	drag and drop	*/

	/*	Make the pack_box a DnD destination	*/
	gtk_drag_dest_set(
		pack_box,
		GTK_DEST_DEFAULT_MOTION | GTK_DEST_DEFAULT_HIGHLIGHT,
		target_list,
		n_targets,
		GDK_ACTION_MOVE
);
	/*	Make the image_boxes a source widget	*/
	gtk_drag_source_set(
		and_box,
		GDK_BUTTON1_MASK,
		target_list,
		n_targets,	
		GDK_ACTION_MOVE
);
	/*	Connect signals		*/
		
        /* All possible destination signals */
        g_signal_connect (pack_box, "drag-data-received", G_CALLBACK(drag_data_received_handl), NULL);
        g_signal_connect (pack_box, "drag-leave", G_CALLBACK (drag_leave_handl), NULL);
        g_signal_connect (pack_box, "drag-motion", G_CALLBACK (drag_motion_handl), NULL);
        g_signal_connect (pack_box, "drag-drop", G_CALLBACK (drag_drop_handl), NULL);

        /* All possible source signals */
        g_signal_connect (and_box, "drag-data-get", G_CALLBACK (drag_data_get_handl), NULL);
//        g_signal_connect (and_box, "drag-data-delete", G_CALLBACK (drag_data_delete_handl), NULL);
        g_signal_connect (and_box, "drag-begin", G_CALLBACK (drag_begin_handl), NULL);
        g_signal_connect (and_box, "drag-end", G_CALLBACK (drag_end_handl), NULL);

	/*	dispaly */
	gtk_window_fullscreen((GtkWindow *)window);
	gtk_widget_show_all(window);

	gtk_main();

	if(argc == 2){	
		if(strcmp(argv[1], "-h") == 0)
			 usage();
}
	return 0;
}

