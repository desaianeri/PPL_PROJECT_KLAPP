#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
        int gtype;
        int ig;
        struct node *left;
        struct node *right;
}node;

typedef struct queue{

        node *arr[500];
        int iq;
        int jq;

}queue;

typedef struct stack{
        int no[500];
        int is;
}stack;

typedef node *tree;

stack s, rs;
int count = 0;
queue q;
tree t;
node *p;
int res = -1;
int flag = 0;

GtkWidget *aim, *oim, *nim, *in0im, *in1im, *hu, *hd, *outim, *outim_ch, *naim, *noim, *exorim, *no_out;
GtkWidget *layout, *window ;
GtkWidget *and_win, *or_win, *not_win, *in0_win, *in1_win, *out_win, *hu_win, *hd_win, *nand_win, *nor_win, *exor_win;
GdkColor color;
GtkWidget *and_button, *or_button,*not_button, *in0_button, *help_lines_up, *help_lines_down, *run_button, *clear_button, *nand_button, *nor_button;
GtkWidget *exor_button;
GtkWidget *in1_button, *out_button, *box, *handlebox, *eventbox;

void sinit(stack *s);
void push(stack *s, int);
int pop(stack *s);
int sempty(stack *s);
int sfull(stack *s);
void qinit(queue *q);
void enqueue(queue*q, node *);
node *dequeue(queue *q);
int qempty(queue *q);
int qfull(queue *q);
void init(tree *);
void printree(tree t);
void printstack(stack *);
void store_stack(tree t);
int evaluate(stack *);

enum gates{AND, OR, NOT, IN_0, OUT, IN_1, HU, HD, ERR, NAND, NOR, EXOR};

void qinit(queue *q){
        q -> iq = q -> jq = 0;
}

void enqueue(queue *q, node *s){
        q -> arr[q -> iq] = s;
        (q -> iq)++;
}

node *dequeue(queue *q){
        node *tmp;
        tmp = q -> arr[q -> jq];
        (q -> jq)++;
        return tmp;
}

int qempty(queue *q){
        return q -> iq == q -> jq;
}

int qfull(queue *q){
        return q -> iq == 500;
}      

void sinit(stack *s){
        s -> is = 0;
}

void push(stack *s, int pu){
        s -> no[s -> is] = pu;
        (s -> is)++;
}

int pop(stack *s){
        int po;
        po = s -> no[s -> is - 1];
        (s -> is)--;
	return po;
}

int sempty(stack *s){
        return s -> is == 0;
}

int sfull(stack *s){
        return s -> is == 500;
}

void init(tree *t){
        *t = NULL;
}

void clear(GtkWidget *widget, gpointer data){
	init(&t);	
	sinit(&s);
	sinit(&rs);
	qinit(&q);
	count = 0;
	flag = 0;
	return;
}

gboolean on_button_press(GtkWidget* widget, GdkEventButton *event, GdkWindowEdge edge) {
        if (event->type == GDK_BUTTON_PRESS) {
                if (event->button == 1) {
                        gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                        event->button,
                        event->x_root,
                        event->y_root,
                        event->time);

//                      printf("%f\n%f\n",event -> x_root, event -> y_root);
}

}

        return TRUE;
}

void printree(tree t1){

	queue q1;
	node *p1;
	qinit(&q1);
	p1 = t1;
	if(!p1)
		return;
	printf("levelwise: [");
	enqueue(&q1, p1);
//	printf("%d\n", p1 -> gtype);
	while(!qempty(&q1)) {


		p1 = dequeue(&q1);
		printf("%d ", p1->gtype);
		if(p1->left)
			enqueue(&q1, p1->left);

		if(p1->right)
			enqueue(&q1, p1->right);
		

	}
	printf("]\n");

}


void call_store_stack(GtkWidget *widget, gpointer data){
	GtkWidget *err_win;
	GtkWidget *quit;
	GtkWidget *qbox;
	int ch1, ch2, cflag = 1;

	store_stack(t);
//	printstack(&s);

{
        ch1 = pop(&s);
        if(ch1 != IN_0 && ch1 != IN_1){
                gtk_widget_destroy(outim);
                outim = gtk_image_new_from_file("output_1.png");
                gtk_container_add(GTK_CONTAINER(out_win), outim);
                gtk_widget_show(outim);
                cflag = 0;
}

        ch2 = pop(&s);
        if(ch2 != NOT && ch2 != IN_0 && ch2 != IN_1){
                gtk_widget_destroy(outim);
                outim = gtk_image_new_from_file("output_1.png");
                gtk_container_add(GTK_CONTAINER(out_win), outim);
                gtk_widget_show(outim);
                cflag = 0;
}
        push(&s, ch2);
        push(&s, ch1);
        if(cflag == 0)
                return ;
}




                res = evaluate(&s);
                printf("%d\n", res);


                if(flag == 1){
                        if(res == 1){
                        gtk_widget_destroy(outim);
                        outim = gtk_image_new_from_file("out_11.png");
                        gtk_container_add(GTK_CONTAINER(out_win), outim);
                        gtk_widget_show(outim);
}
                else if(res == 0){
                        gtk_widget_destroy(outim);
                        outim = gtk_image_new_from_file("out_1.png");
                        gtk_container_add(GTK_CONTAINER(out_win), outim);
                        gtk_widget_show(outim);
}
                return ;
}



         if(flag == 0){
                err_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
                gtk_window_set_position(GTK_WINDOW(err_win), GTK_WIN_POS_CENTER);

                gtk_window_set_default_size(GTK_WINDOW(err_win), 77 , 48);
                gtk_window_set_decorated(GTK_WINDOW(err_win), FALSE);

                quit = gtk_button_new_with_label("QUIT");
                qbox = gtk_vbox_new(FALSE, 0);

                gtk_box_pack_start(GTK_BOX(qbox), quit,TRUE, TRUE, 0);
                no_out = gtk_image_new_from_file("noout.png");
                gtk_box_pack_start(GTK_BOX(qbox), no_out,TRUE, TRUE, 0);
                gtk_widget_show(no_out);
                gtk_container_add(GTK_CONTAINER(err_win), qbox);
                gtk_widget_show_all(err_win);

                g_signal_connect_swapped(quit, "clicked", G_CALLBACK(gtk_widget_destroy), err_win);
		return ;
}

        	else{
	                err_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	                gtk_window_set_position(GTK_WINDOW(err_win), GTK_WIN_POS_CENTER);

	                gtk_window_set_default_size(GTK_WINDOW(err_win), 77 , 48);
	                gtk_window_set_decorated(GTK_WINDOW(err_win), FALSE);

        	        quit = gtk_button_new_with_label("QUIT");
	                qbox = gtk_vbox_new(FALSE, 0);

	                gtk_box_pack_start(GTK_BOX(qbox), quit,TRUE, TRUE, 0);
	                no_out = gtk_image_new_from_file("noout1.png");
    	                gtk_box_pack_start(GTK_BOX(qbox), no_out,TRUE, TRUE, 0);
        	        gtk_widget_show(no_out);
	                gtk_container_add(GTK_CONTAINER(err_win), qbox);
	                gtk_widget_show_all(err_win);

	                g_signal_connect_swapped(quit, "clicked", G_CALLBACK(gtk_widget_destroy), err_win);
			return ;
}
	return ;
}

void store_stack(tree t){

        if(t == NULL)
                return ;

        push(&s, t -> gtype);
//      printf("%d\n", s.no[s.is]);
        store_stack(t -> left);
        store_stack(t -> right);
}


int evaluate(stack *s){
	int x, y, p, n;
	while(!sempty(s)){
		p = pop(s);
		switch(p){
			case IN_0 : push(&rs, 0);
				    break;
			case IN_1 : push(&rs, 1);
				    break;
			case AND : x = pop(&rs);
				   y = pop(&rs);
		   		   if(x + y == 2)
					push(&rs, 1);
				   else
					push(&rs, 0);
				   break;
			case OR : x = pop(&rs);
                                  y = pop(&rs);
                                  if(x + y == 0)
                                        push(&rs, 0);
                                  else
                                        push(&rs, 1);
                                  break;
			case NOT : n = pop(&rs);
				   if(n == 0)
					push(&rs, 1);
				   else
					push(&rs, 0);
			  	   break;

			case NAND : x = pop(&rs);
				    y = pop(&rs);
				    if((x + y) == 2)
					push(&rs, 0);
				    else
					push(&rs, 1);
				    break;
                        case NOR : x = pop(&rs);
                                   y = pop(&rs);
                                   if(x + y == 0)
                                        push(&rs, 1);
                                   else
                                        push(&rs, 0);
                                   break;
                        case EXOR : x = pop(&rs);
                                    y = pop(&rs);
                                  if(x + y == 1)
                                        push(&rs, 1);
				  else
					push(&rs, 0);
                                  break;


}
}	
        
	return pop(&rs);
      
}

void printstack(stack *s){
	int i = 0;
	for(i = 0; i < s -> is; i++)
		printf("%d\n", s -> no[i]);	
	return ;
}

static gboolean key_event(GtkWidget *widget, GdkEventKey *event){

//    g_printerr("%s\n", gdk_keyval_name (event->keyval));
    if(strcmp(gdk_keyval_name (event->keyval), "Escape") == 0){
		gtk_main_quit();	
}
    return FALSE;
}

void my_getsize(GtkWidget *widget, GtkAllocation *allocation, void *data) {
	printf("width = %d, height = %d\n", allocation -> width, allocation -> height);
}

static void nand_dis(GtkWidget *widget, gpointer data){
        static int nai = 1;
        node *nand;

        naim = gtk_image_new_from_file("nand.png");

        nand_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(nand_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(nand_win), 77 , 48);
        gtk_window_set_decorated(GTK_WINDOW(nand_win), FALSE);
        gtk_widget_add_events(nand_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(nand_win), naim);
        gtk_widget_show(naim);


        g_signal_connect(G_OBJECT(nand_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(nand_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(nand_win));


        gtk_layout_put(GTK_LAYOUT(layout),nand_win , 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(nand_win,  GTK_STATE_NORMAL, &color);

//      g_signal_connect(aim, "size-allocate", G_CALLBACK(my_getsize), NULL);
        /*      create node     */
        nand = (node *)malloc(sizeof(node));
        nand -> gtype = NAND;
        nand -> ig = nai;
        nai++;
        nand -> left = NULL;
        nand -> right = NULL;

        /*      linking */

        enqueue(&q, nand);
        if(t == NULL){
                t = nand;
                p = dequeue(&q);
                return ;
}

        if(p -> gtype == NOT && count == 1){
                p = dequeue(&q);
                count = 0;
}

        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}


         if(count == 0){
                p -> left = nand;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = nand;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                        p = dequeue(&q);
                count = 0;
                p -> left = nand;
                count++ ;
                return ;
}

}




static void and_dis(GtkWidget *widget, gpointer data){
	static int ai = 1;
	node *and;	

	aim = gtk_image_new_from_file("and.png");

	and_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(and_win), GTK_WIN_POS_CENTER);

	gtk_window_set_default_size(GTK_WINDOW(and_win), 77 , 48);
	gtk_window_set_decorated(GTK_WINDOW(and_win), FALSE);
	gtk_widget_add_events(and_win, GDK_BUTTON_PRESS_MASK);


	gtk_container_add(GTK_CONTAINER(and_win), aim);
	gtk_widget_show(aim);


	g_signal_connect(G_OBJECT(and_win), "button-press-event",
	G_CALLBACK(on_button_press), NULL);

	g_signal_connect(G_OBJECT(and_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(and_win));


        gtk_layout_put(GTK_LAYOUT(layout),and_win , 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(and_win,  GTK_STATE_NORMAL, &color);

//	g_signal_connect(aim, "size-allocate", G_CALLBACK(my_getsize), NULL);

	/*	create node	*/
	and = (node *)malloc(sizeof(node));
	and -> gtype = AND;
	and -> ig = ai;
	ai++;
	and -> left = NULL;
	and -> right = NULL;

	/*	linking	*/	

        enqueue(&q, and);
        if(t == NULL){
                t = and;
                p = dequeue(&q);
                return ;
}

	if(p -> gtype == NOT && count == 1){
		p = dequeue(&q);
		count = 0;
}

        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}


	 if(count == 0){
		p -> left = and;
		count++ ;
		return ;
}
	 if(count == 1){
		p -> right = and;
		count++ ;
		return ;
}
	 if(count == 2){
		p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                        p = dequeue(&q);
		count = 0;
		p -> left = and;
		count++ ;
		return ;
}

}

static void exor_dis(GtkWidget *widget, gpointer data){

        static int exori = 1;
        node *exor;

        exorim = gtk_image_new_from_file("exor.png");

        exor_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(exor_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(exor_win), 77 , 48);
        gtk_window_set_decorated(GTK_WINDOW(exor_win), FALSE);
        gtk_widget_add_events(exor_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(exor_win), exorim);
        gtk_widget_show(exorim);


        g_signal_connect(G_OBJECT(exor_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(exor_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(exor_win));


        gtk_layout_put(GTK_LAYOUT(layout),exor_win, 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(exor_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(oim, "size-allocate", G_CALLBACK(my_getsize), NULL);


        /*      create node     */
        exor = (node *)malloc(sizeof(node));
        exor -> gtype = EXOR;
        exor -> ig = exori;
        exori++;
        exor -> left = NULL;
        exor -> right = NULL;

        /*      linking */

        enqueue(&q, exor);
        if(t == NULL){
                t = exor;
                p = dequeue(&q);
                return ;
}


        if(p -> gtype == NOT && count == 1){
                p = dequeue(&q);
                count = 0;
}
        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}



         if(count == 0){
                p -> left = exor;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = exor;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                        p = dequeue(&q);
                count = 0;
                p -> left = exor;
                count++ ;
                return ;
}

}


static void nor_dis(GtkWidget *widget, gpointer data){

        static int noi = 1;
        node *nor;

        noim = gtk_image_new_from_file("nor.png");

        nor_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(nor_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(nor_win), 77 , 48);
        gtk_window_set_decorated(GTK_WINDOW(nor_win), FALSE);
        gtk_widget_add_events(nor_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(nor_win), noim);
        gtk_widget_show(noim);


        g_signal_connect(G_OBJECT(nor_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(nor_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(nor_win));


        gtk_layout_put(GTK_LAYOUT(layout),nor_win, 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(nor_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(oim, "size-allocate", G_CALLBACK(my_getsize), NULL);


        /*      create node     */
        nor = (node *)malloc(sizeof(node));
        nor -> gtype = NOR;
        nor -> ig = noi;
        noi++;
        nor -> left = NULL;
        nor -> right = NULL;

        /*      linking */

        enqueue(&q, nor);
        if(t == NULL){
                t = nor;
                p = dequeue(&q);
                return ;
}


        if(p -> gtype == NOT && count == 1){
                p = dequeue(&q);
                count = 0;
}
        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}



         if(count == 0){
                p -> left = nor;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = nor;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                        p = dequeue(&q);
                count = 0;
                p -> left = nor;
                count++ ;
                return ;
}

}


static void or_dis(GtkWidget *widget, gpointer data){

	static int oi = 1;	
	node *or;	

        oim = gtk_image_new_from_file("or.png");

        or_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(or_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(or_win), 77 , 48);
        gtk_window_set_decorated(GTK_WINDOW(or_win), FALSE);
        gtk_widget_add_events(or_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(or_win), oim);
        gtk_widget_show(oim);


        g_signal_connect(G_OBJECT(or_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(or_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(or_win));


        gtk_layout_put(GTK_LAYOUT(layout),or_win, 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(or_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(oim, "size-allocate", G_CALLBACK(my_getsize), NULL);

        /*      create node     */
        or = (node *)malloc(sizeof(node));
        or -> gtype = OR;
        or -> ig = oi;
        oi++;
        or -> left = NULL;
        or -> right = NULL;

        /*      linking */

        enqueue(&q, or);
        if(t == NULL){
                t = or;
                p = dequeue(&q);
                return ;
}


        if(p -> gtype == NOT && count == 1){
                p = dequeue(&q);
                count = 0;
}
        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}



         if(count == 0){
                p -> left = or;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = or;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                        p = dequeue(&q);
                count = 0;
                p -> left = or;
                count++ ;
                return ;
}

}

static void not_dis(GtkWidget *widget, gpointer data){

	node *not;
	static int ni = 1;

        nim = gtk_image_new_from_file("not.png");

        not_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(not_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(not_win), 77 , 48);
        gtk_window_set_decorated(GTK_WINDOW(not_win), FALSE);
        gtk_widget_add_events(not_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(not_win), nim);
        gtk_widget_show(nim);


        g_signal_connect(G_OBJECT(not_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(not_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(not_win));


        gtk_layout_put(GTK_LAYOUT(layout),not_win, 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(not_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(nim, "size-allocate", G_CALLBACK(my_getsize), NULL);

        /*      create node     */
        not = (node *)malloc(sizeof(node));
        not -> gtype = NOT;
        not -> ig = ni;
        ni++;
        not -> left = NULL;
        not -> right = NULL;

        /*      linking */
        enqueue(&q, not);
        if(t == NULL){
                t = not;
                p = dequeue(&q);
                return ;
}


        if(p -> gtype == NOT && count == 1){
                p = dequeue(&q);
                count = 0;
}
        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}


         if(count == 0){
                p -> left = not;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = not;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                        p = dequeue(&q);
                count = 0;
                p -> left = not;
                count++ ;
                return ;
}

}


static void in0_dis(GtkWidget *widget, gpointer data){
	node *in0;
	static int i0 = 1;

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


        gtk_layout_put(GTK_LAYOUT(layout),in0_win, 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(in0_win,  GTK_STATE_NORMAL, &color);

//      g_signal_connect(in0im, "size-allocate", G_CALLBACK(my_getsize), NULL);

        /*      create node     */
        in0 = (node *)malloc(sizeof(node));
        in0 -> gtype = IN_0;
        in0 -> ig = i0;
        i0++;
        in0 -> left = NULL;
        in0 -> right = NULL;
        /*      linking */
        enqueue(&q, in0);
        if(t == NULL){
                t = in0;
                p = dequeue(&q);
                return ;
}


        if(p -> gtype == NOT && count == 1){
                p = dequeue(&q);
                count = 0;
}
        if(p -> gtype == IN_0 || p -> gtype == IN_1){
                p = dequeue(&q);
                return;
}


         if(count == 0){
                p -> left = in0;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = in0;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
                while(p -> gtype == IN_0 || p -> gtype == IN_1)
                       p =  dequeue(&q);
                count = 0;
                p -> left = in0;
                count++ ;
                return ;
}

}

static void in1_dis(GtkWidget *widget, gpointer data){
	static int i1;
	node *in1;
	

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


        gtk_layout_put(GTK_LAYOUT(layout),in1_win, 50, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(in1_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(in1im, "size-allocate", G_CALLBACK(my_getsize), NULL);


        /*      create node     */
        in1 = (node *)malloc(sizeof(node));
        in1 -> gtype = IN_1;
        in1 -> ig = i1;
        i1++;
        in1 -> left = NULL;
        in1 -> right = NULL;

        /*      linking */
        enqueue(&q, in1);
        if(t == NULL){
                t = in1;
                p = dequeue(&q);
                return ;
}


        if((p -> gtype == NOT && count == 1)){
                p = dequeue(&q);
                count = 0;
}

	if(p -> gtype == IN_0 || p -> gtype == IN_1){
		p = dequeue(&q);
		return;
}

         if(count == 0){
                p -> left = in1;
                count++ ;
                return ;
}
         if(count == 1){
                p -> right = in1;
                count++ ;
                return ;
}
         if(count == 2){
                p = dequeue(&q);
		while(p -> gtype == IN_0 || p -> gtype == IN_1)
			p = dequeue(&q);
                count = 0;
                p -> left = in1;
                count++ ;
                return ;
}

}
static void out_dis(GtkWidget *widget, gpointer data){

	flag++;

        outim = gtk_image_new_from_file("output_0.png");

        out_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(out_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(out_win),54 , 55);
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

//        g_signal_connect(outim, "size-allocate", G_CALLBACK(my_getsize), NULL);

}

static void hu_dis(GtkWidget *widget, gpointer data){


        hu = gtk_image_new_from_file("h1.png");

        hu_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(hu_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(hu_win), 27 , 92);
        gtk_window_set_decorated(GTK_WINDOW(hu_win), FALSE);
        gtk_widget_add_events(hu_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(hu_win), hu);
        gtk_widget_show(hu);


        g_signal_connect(G_OBJECT(hu_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(hu_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(hu_win));


        gtk_layout_put(GTK_LAYOUT(layout),hu_win ,0, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(hu_win,  GTK_STATE_NORMAL, &color);

//       g_signal_connect(hu, "size-allocate", G_CALLBACK(my_getsize), NULL);

}


static void hd_dis(GtkWidget *widget, gpointer data){


        hd = gtk_image_new_from_file("h2.png");

        hd_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(hd_win), GTK_WIN_POS_CENTER);

        gtk_window_set_default_size(GTK_WINDOW(hd_win), 27 , 95);
        gtk_window_set_decorated(GTK_WINDOW(hd_win), FALSE);
        gtk_widget_add_events(hd_win, GDK_BUTTON_PRESS_MASK);


        gtk_container_add(GTK_CONTAINER(hd_win), hd);
        gtk_widget_show(hd);


        g_signal_connect(G_OBJECT(hd_win), "button-press-event",
        G_CALLBACK(on_button_press), NULL);

        g_signal_connect(G_OBJECT(hd_win), "destroy",
        G_CALLBACK(gtk_main_quit), G_OBJECT(hd_win));


        gtk_layout_put(GTK_LAYOUT(layout),hd_win, 0, 100);

        gtk_widget_show_all(layout);

        /*      set background color    */

        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(hd_win,  GTK_STATE_NORMAL, &color);

//        g_signal_connect(hd, "size-allocate", G_CALLBACK(my_getsize), NULL);


}


int main( int argc, char *argv[]){

	gtk_init(&argc, &argv);

        /*      Initialize the tree     */
        init(&t);

	sinit(&s);
	sinit(&rs);
	qinit(&q);


	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 290, 200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	/*	layout	*/
	layout = gtk_layout_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER (window), layout);

	/*	close window	*/
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
	run_button = gtk_button_new_with_label("RUN");
        clear_button = gtk_button_new_with_label("CLEAR");
	nand_button = gtk_button_new_with_label("NAND");
	nor_button = gtk_button_new_with_label("NOR");
	exor_button = gtk_button_new_with_label("EX-OR");

        /*       box    */
        box = gtk_hbox_new(FALSE, 0);

        gtk_box_pack_start(GTK_BOX(box), and_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), or_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), not_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), nor_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), nand_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), exor_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), in0_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), in1_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), out_button ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), help_lines_up ,TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), help_lines_down ,TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box), run_button, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box), clear_button, TRUE, TRUE, 0);

        gtk_container_add(GTK_CONTAINER(handlebox), box);

        /*      set background color    */
        gdk_color_parse("black", &color);
        gtk_widget_modify_bg(layout,  GTK_STATE_NORMAL, &color);
    
        /*      event box       */

        eventbox = gtk_event_box_new();
        gtk_layout_put(GTK_LAYOUT(layout) ,eventbox, 0, 0);
        gtk_widget_show(eventbox);
                         
	/*	button signals	*/
	g_signal_connect(and_button, "clicked", G_CALLBACK(and_dis), NULL);
        g_signal_connect(or_button, "clicked", G_CALLBACK(or_dis), NULL);
        g_signal_connect(not_button, "clicked", G_CALLBACK(not_dis), NULL);
        g_signal_connect(in0_button, "clicked", G_CALLBACK(in0_dis), NULL);
        g_signal_connect(in1_button, "clicked", G_CALLBACK(in1_dis), NULL);
        g_signal_connect(help_lines_up, "clicked", G_CALLBACK(hu_dis), NULL);
        g_signal_connect(help_lines_down, "clicked", G_CALLBACK(hd_dis), NULL);
	g_signal_connect(run_button, "clicked", G_CALLBACK(call_store_stack), NULL);
        g_signal_connect(out_button, "clicked", G_CALLBACK(out_dis), NULL);
        g_signal_connect(clear_button, "clicked", G_CALLBACK(clear), NULL);
        g_signal_connect(nand_button, "clicked", G_CALLBACK(nand_dis), NULL);
        g_signal_connect(nor_button, "clicked", G_CALLBACK(nor_dis), NULL);
        g_signal_connect(exor_button, "clicked", G_CALLBACK(exor_dis), NULL);     

	/*	Key Press	*/
	g_signal_connect(window, "key-release-event", G_CALLBACK(key_event), NULL);

	gtk_widget_show(layout);
	gtk_window_fullscreen((GtkWindow *)window);
	
	gtk_widget_show_all(window);

	gtk_main();

    return 0;
}
