project : dls.c
	cc -Wall -o project -g dls.c `pkg-config --cflags --libs gtk+-2.0`
clean : 
	rm *.o

	
