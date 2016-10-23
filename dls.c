#include<stdio.h>
#include<gtk/gtk.h>

GtkWidget *aim, *oim, *nim, *in0im, *in1im, *outim, *hu, *hd;
GtkWidget *layout, *window, *eventbox ;
GtkWidget *and_win, *or_win, *not_win, *in0_win, *in1_win, *out_win, *hu_win, *hd_win;
GdkColor color;
int ax, ay, ox, oy, nx, ny, in0x, in0y, in1x, in1y;
GtkWidget *and_button, *or_button, *not_button, *in0_button, *help_lines_up, *help_lines_down;
GtkWidget *in1_button, *out_button, *box, *handlebox;

gboolean on_button_press(GtkWidget* widget, GdkEventButton *event, GdkWindowEdge edge) {
	if (event->type == GDK_BUTTON_PRESS) {
		if (event->button == 1) {
			gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
         	        event->button,
                        event->x_root,
                        event->y_root,
                        event->time);

//			printf("%f\n%f\n",event -> x, event -> y);
}

}


  return TRUE;
}


void my_getsize(GtkWidget *widget, GtkAllocation *allocation, void *data) {
	printf("width = %d, height = %d\n", allocation -> width, allocation -> height);
}

static void and_dis(GtkWidget *widget, gpointer data){


	aim = gtk_image_new_from_file("and.png");

	and_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(and_win), GTK_WIN_POS_CENTER);

	gtk_window_set_default_size(GTK_WINDOW(and_win),217 , 100);
	gtk_window_set_decorated(GTK_WINDOW(and_win), FALSE);
	gtk_widget_add_events(and_win, GDK_BUTTON_PRESS_MASK);


	gtk_container_add(GTK_CONTAINER(and_win), aim);
	gtk_widget_show(aim);


	g_signal_connect(G_OBJECT(and_win), "button-press-event",
	G_CALLBACK(on_button_press), NULL);

	g_signal_connect(G_OBJECT(and_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(and_win));


        gtk_layout_put(GTK_LAYOUT(layout),and_win ,100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(and_win,  GTK_STATE_NORMAL, &color);

//	g_signal_connect(aim, "size-allocate", G_CALLBACK(my_getsize), NULL);

}

static void hu_dis(GtkWidget *widget, gpointer data){


        hu = gtk_image_new_from_file("h1.png");

        hu_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(hu_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(hu_win), 21 , 125);
        gtk_window_set_decorated(GTK_WINDOW(hu_win), FALSE);
        gtk_widget_add_events(hu_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(hu_win), hu);
        gtk_widget_show(hu);


        g_signal_connect(G_OBJECT(hu_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(hu_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(hu_win));


        gtk_layout_put(GTK_LAYOUT(layout),hu_win ,100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(hu_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(hu, "size-allocate", G_CALLBACK(my_getsize), NULL);

}


static void hd_dis(GtkWidget *widget, gpointer data){


        hd = gtk_image_new_from_file("h2.png");

        hd_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(hd_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(hd_win),21 , 125);
        gtk_window_set_decorated(GTK_WINDOW(hd_win), FALSE);
        gtk_widget_add_events(hd_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(hd_win), hd);
        gtk_widget_show(hd);


        g_signal_connect(G_OBJECT(hd_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(hd_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(hd_win));


        gtk_layout_put(GTK_LAYOUT(layout),hd_win, 100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(hd_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(hd, "size-allocate", G_CALLBACK(my_getsize), NULL);

}


static void or_dis(GtkWidget *widget, gpointer data){


        oim = gtk_image_new_from_file("or.png");

        or_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(or_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(or_win),217 , 100);
        gtk_window_set_decorated(GTK_WINDOW(or_win), FALSE);
        gtk_widget_add_events(or_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(or_win), oim);
        gtk_widget_show(oim);


        g_signal_connect(G_OBJECT(or_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(or_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(or_win));


        gtk_layout_put(GTK_LAYOUT(layout),or_win, 100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(or_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(oim, "size-allocate", G_CALLBACK(my_getsize), NULL);

}

static void not_dis(GtkWidget *widget, gpointer data){


        nim = gtk_image_new_from_file("not.png");

        not_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(not_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(not_win), 217 , 100);
        gtk_window_set_decorated(GTK_WINDOW(not_win), FALSE);
        gtk_widget_add_events(not_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(not_win), nim);
        gtk_widget_show(nim);


        g_signal_connect(G_OBJECT(not_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(not_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(not_win));


        gtk_layout_put(GTK_LAYOUT(layout),not_win, 100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(not_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(nim, "size-allocate", G_CALLBACK(my_getsize), NULL);

}


static void in0_dis(GtkWidget *widget, gpointer data){


        in0im = gtk_image_new_from_file("in0.png");

        in0_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(in0_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(in0_win), 100 , 30);
        gtk_window_set_decorated(GTK_WINDOW(in0_win), FALSE);
        gtk_widget_add_events(in0_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(in0_win), in0im);
        gtk_widget_show(in0im);


        g_signal_connect(G_OBJECT(in0_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(in0_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(in0_win));


        gtk_layout_put(GTK_LAYOUT(layout),in0_win, 100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(in0_win,  GTK_STATE_NORMAL, &color);

//      g_signal_connect(in0im, "size-allocate", G_CALLBACK(my_getsize), NULL);

}

static void in1_dis(GtkWidget *widget, gpointer data){


        in1im = gtk_image_new_from_file("in1.png");

        in1_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(in1_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(in1_win),100 , 30);
        gtk_window_set_decorated(GTK_WINDOW(in1_win), FALSE);
        gtk_widget_add_events(in1_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(in1_win), in1im);
        gtk_widget_show(in1im);


        g_signal_connect(G_OBJECT(in1_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(in1_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(in1_win));


        gtk_layout_put(GTK_LAYOUT(layout),in1_win, 100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(hd_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(in1im, "size-allocate", G_CALLBACK(my_getsize), NULL);

}
static void out_dis(GtkWidget *widget, gpointer data){


        outim = gtk_image_new_from_file("outbulb.png");

        out_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(out_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(out_win), 69, 65);
        gtk_window_set_decorated(GTK_WINDOW(out_win), FALSE);
        gtk_widget_add_events(out_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(out_win), outim);
        gtk_widget_show(outim);


        g_signal_connect(G_OBJECT(out_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(out_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(out_win));


        gtk_layout_put(GTK_LAYOUT(layout),out_win, 100, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(out_win,  GTK_STATE_NORMAL, &color);

        g_signal_connect(outim, "size-allocate", G_CALLBACK(my_getsize), NULL);

}

int main( int argc, char *argv[]){

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 290, 200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window), layout);

	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	/*      handlebox       */
        handlebox = gtk_handle_box_new();
	gtk_layout_put(GTK_LAYOUT(layout), handlebox, 100, 100);

        /*      buttons         */
	help_lines_up = gtk_button_new_with_label("HELPING LINES UP");
	help_lines_down = gtk_button_new_with_label("HELPING LINES DOWN");
        and_button = gtk_button_new_with_label("AND");
        or_button = gtk_button_new_with_label("OR");
        not_button = gtk_button_new_with_label("NOT");
        in0_button = gtk_button_new_with_label("INPUT_0");
        in1_button = gtk_button_new_with_label("INPUT_1");
        out_button = gtk_button_new_with_label("OUPUT");

        /*       box    */
        box = gtk_vbox_new(FALSE, 0);

        gtk_box_pack_start(GTK_BOX(box), and_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), or_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), not_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), in0_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), in1_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), out_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), help_lines_up ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), help_lines_down ,TRUE, TRUE, 0);


        gtk_container_add(GTK_CONTAINER(handlebox), box);

	/*	event box	*/
        eventbox = gtk_event_box_new();
        gtk_layout_put(GTK_LAYOUT(layout) ,eventbox, 0, 0);
        gtk_widget_show(eventbox);



        /*      set background color    */
        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(layout,  GTK_STATE_NORMAL, &color);
                              
	/*	button signals	*/
	g_signal_connect(and_button, "clicked", G_CALLBACK(and_dis), NULL);
        g_signal_connect(or_button, "clicked", G_CALLBACK(or_dis), NULL);
        g_signal_connect(not_button, "clicked", G_CALLBACK(not_dis), NULL);
        g_signal_connect(in0_button, "clicked", G_CALLBACK(in0_dis), NULL);
        g_signal_connect(in1_button, "clicked", G_CALLBACK(in1_dis), NULL);
        g_signal_connect(out_button, "clicked", G_CALLBACK(out_dis), NULL);
        g_signal_connect(help_lines_up, "clicked", G_CALLBACK(hu_dis), NULL);
        g_signal_connect(help_lines_down, "clicked", G_CALLBACK(hd_dis), NULL);


	gtk_widget_show(layout);
	gtk_window_fullscreen((GtkWindow *)window);

	gtk_widget_show_all(window);

	gtk_main();

    return 0;
}
