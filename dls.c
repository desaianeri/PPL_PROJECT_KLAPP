#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<cairo.h>

GtkWidget *and_button, *window, *event_box, *box;
GtkWidget *or_button, *darea, *pack_box, *and_box;
GtkWidget *not_button, *image;
GtkWidget *in0_button;
GtkWidget *in1_button;
GtkWidget *out_button;
GtkWidget *wires, *handlebox;
GdkColor color;

static void not_dis(GtkWidget *widget, gpointer data){

        image = gtk_image_new_from_file("not.png");
        gtk_box_pack_start(GTK_BOX(and_box), image, TRUE, TRUE , 0);
        gtk_widget_show(image);
        gtk_widget_show(and_box);

}

static int delete(GtkWidget *widget, GdkEvent *event,  gpointer data){

	gtk_main_quit();
	return 0;
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
	gtk_container_add(GTK_CONTAINER(pack_box), and_box);

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

	/*	images	*/


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

	
        /*      closing window  */
        g_signal_connect (window, "delete-event",G_CALLBACK(delete), NULL);

	/*	button event handling	*/
        g_signal_connect(not_button, "clicked", G_CALLBACK(not_dis), NULL);


	/*	dispaly */
	gtk_window_fullscreen((GtkWindow *)window);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}

