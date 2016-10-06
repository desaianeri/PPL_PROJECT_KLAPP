#include<SDL.h>
#include<stdio.h>
#include<SDL2/SDL_image.h>

int h, w;
void init();
void quit();
void andl();
void orl();
void notl();
void in0();
void in1();
void out();

SDL_Window *window;
SDL_Renderer *ren;
SDL_Texture *im[11];
SDL_Rect r[11];

void init(){
        SDL_Init(SDL_INIT_EVERYTHING);

        window = SDL_CreateWindow("Digital Logic Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1500, 1000, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

        if (window == NULL) {
                printf("Could not create window: %s\n", SDL_GetError());
                return ;
}


	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void quit(){
	int i;
	for(i = 0; i < 6; i++)
		SDL_DestroyTexture(im[i]);
	SDL_DestroyRenderer(ren);	
	SDL_DestroyWindow(window);
        SDL_Quit();

}

void andl(){
        im[0] = IMG_LoadTexture(ren,"and_label.png");
        SDL_QueryTexture(im[0], NULL, NULL, &w, &h);

        r[0].x = 1050;
        r[0].y = 20;
        r[0].w = 250;
        r[0].h = 70;

}

void orl(){
	im[1] = IMG_LoadTexture(ren, "or_label.png");
	SDL_QueryTexture(im[1], NULL, NULL, &w, &h);

	r[1].x = 1050;
	r[1].y = 120;
	r[1].w = 250;
	r[1].h = 70;

}

void notl(){

        im[2] = IMG_LoadTexture(ren, "not_label.png");
        SDL_QueryTexture(im[2], NULL, NULL, &w, &h);

        r[2].x = 1050;
        r[2].y = 210;
        r[2].w = 250;
        r[2].h = 70;

}

void in0(){

        im[3] = IMG_LoadTexture(ren, "input_0.png");
        SDL_QueryTexture(im[3], NULL, NULL, &w, &h);

        r[3].x = 1050;
        r[3].y = 310;
        r[3].w = 250;
        r[3].h = 70;

}

void in1(){
        im[4] = IMG_LoadTexture(ren, "input_1.png");
        SDL_QueryTexture(im[4], NULL, NULL, &w, &h);

        r[4].x = 1050;
        r[4].y = 410;
        r[4].w = 250;
        r[4].h = 70;


}
void out(){
        im[5] = IMG_LoadTexture(ren, "output.png");
        SDL_QueryTexture(im[5], NULL, NULL, &w, &h);

        r[5].x = 1050;
        r[5].y = 510;
        r[5].w = 250;
        r[5].h = 70;

}



int main(int argc, char *argv[]){

	init();
	
	int running = 1, i;
	SDL_SetRenderDrawColor(ren, 255  , 255 ,255 , 255);

	SDL_Event event;
	while(running){

		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT : running = 0;
						break;

}

}
//	andl();
//	orl();
//	notl();
//	in0();
//	in1();
	out();

        SDL_RenderClear(ren);
	SDL_RenderCopy(ren, im[5], NULL, &r[5]);
//	for(i = 0; i < 6; i++)
//	        SDL_RenderCopy(ren,im[i],NULL, &r[i]);


        SDL_RenderPresent(ren);

        SDL_UpdateWindowSurface(window);


}

	quit();
	return 0;
}
