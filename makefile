dls : dls.c
	cc -Wall -o dls -g dls.c `pkg-config --cflags --libs gtk+-2.0`
clean : 
	rm *.o

	
