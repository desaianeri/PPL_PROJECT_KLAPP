#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>

GtkWidget *and_button, *window, *event_box, *box;
GtkWidget *or_button, *darea, *pack_box, *image;
GtkWidget *not_button; 
GtkWidget *in0_button;
GtkWidget *in1_button;
GtkWidget *out_button;
GtkWidget *wires, *handlebox;
GtkWidget *and_box, *or_box, *not_box, *in0_box, *in1_box, *out_box;
GdkColor color;

/*
typedef struct{
	gchar *target;
	guint flags;
	guint info;
}GtkTargetEntry;
*/
void usage();

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

	/*	drag and drop	*/
//	GtkTargetEntry tar[] = {{"image/jpeg", 0, 0}};
		//	setting a drag source	//
//	gtk_drag_source_set(and_image, GDK_BUTTON1_MASK, tar, 1, GDK_ACTION_MOVE);		//	connect it to all source signals	//
//	g_signal_connect(G_OBJECT(and_box), "drag_begin", G_CALLBACK(on_drag_begin), NULL);
//	g_signal_connect(G_OBJECT(and_button), "drag_data_get", G_CALLBACK(on_drag_data_get), NULL);
//	g_signal_connect(G_OBJECT(and_button), "drag_end", G_CALLBACK(on_drag_end),NULL);

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

