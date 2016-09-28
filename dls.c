#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL/SDL_ttf.h>
int showmenu(SDL_Surface* screen, TTF_Font* font);

int showmenu(SDL_Surface* screen, TTF_Font* font){
	Uint time;
	int x, y, i;
	const int NUMMENU = 6;
	const char* labels[NUMMENU] = {"AND" , "OR", "NOT", "INPUT_1", "INPUT_0", "OUTPUT"};
	SDL_Surface * menus[NUMMENU];
	bool selected[NUMMENU] = {0,0,0,0,0,0};
	SDL_Color color[1] = {{255, 255, 255}};

	/*creating menus on screen*/
	menus[0] = TTF_RenderText_Solid(font, labels[0], color[0]);
        menus[1] = TTF_RenderText_Solid(font, labels[1], color[0]);
        menus[2] = TTF_RenderText_Solid(font, labels[2], color[0]);
        menus[3] = TTF_RenderText_Solid(font, labels[3], color[0]);
        menus[4] = TTF_RenderText_Solid(font, labels[4], color[0]);
        menus[5] = TTF_RenderText_Solid(font, labels[5], color[0]);
	
	/*positioning menus i.e buttons*/
	SDL_Rect pos[NUMMENU];
	pos[0].x = screen -> clip_rect.w/5 - menu[0] -> clip_rect.w/2;
        pos[0].y = screen -> clip_rect.h/5 - menu[0] -> clip_rect.h;
        pos[1].x = screen -> clip_rect.w/5 - menu[1] -> clip_rect.w/2;
        pos[1].y = screen -> clip_rect.h/5 + menu[1] -> clip_rect.h;
        pos[2].x = screen -> clip_rect.w/5 - menu[2] -> clip_rect.w/2;
        pos[2].y = screen -> clip_rect.h/5 - menu[2] -> clip_rect.h;
        pos[3].x = screen -> clip_rect.w/5 - menu[3] -> clip_rect.w/2;
        pos[3].y = screen -> clip_rect.h/5 + menu[3] -> clip_rect.h;
        pos[4].x = screen -> clip_rect.w/5 - menu[4] -> clip_rect.w/2;
        pos[4].y = screen -> clip_rect.h/5 - menu[4] -> clip_rect.h;
        pos[5].x = screen -> clip_rect.w/5 - menu[5] -> clip_rect.w/2;
        pos[5].y = screen -> clip_rect.h/5 + menu[5] -> clip_rect.h;

	SDL_Event event;
	while(1){
		time = SDL_GetTicks();
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_Quit:
				for(i = 0; i < NUMMENU; i++)
					SDL_FreeSurface(menus[i]);
					return -1;							
				case SDL_MOUSEMOTIONDOWN:
					x = event.motion.x;
					y = event.motion.y;

						

}
}
}
} 

int main(int argc, char *argv[]){

	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Window *window;
	
	window = SDL_CreateWindow("Digital Logic Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1100, 900, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
        if (window == NULL) {
        	printf("Could not create window: %s\n", SDL_GetError());
        	return 1;
}
	/*Font type is air(downloaded and font size is 28*/
	TTF_Font *font = TTFOpenFont("air.ttf", 28);



	SDL_Quit();
}
