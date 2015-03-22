#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <SDL/SDL_ttf.h> pour ecrire le score
#include <assert.h>
#include <math.h>
#include "grid.h"
#include "graphics.h"

int TAILLE_CASE = 70;
int TAILLE_ESPACE_ENTRE_CASE = 5;

struct window_s{
	int size_w;
	int size_h;
	SDL_Surface *screen;
	SDL_Event event;
};

window new_window(){
	
	window w = malloc(sizeof(*w));
	assert(w != NULL);

	w->size_w = TAILLE_CASE*GRID_SIDE + TAILLE_ESPACE_ENTRE_CASE*(GRID_SIDE - 1) + 150;
	w->size_h = TAILLE_CASE*GRID_SIDE + TAILLE_ESPACE_ENTRE_CASE*(GRID_SIDE - 1) + 60;

	assert(SDL_Init(SDL_INIT_VIDEO) != -1);
	//assert(TTF_Init() != -1); pour ecrire le score

	w->screen = SDL_SetVideoMode(w->size_w, w->size_h, 32, SDL_HWSURFACE);

	SDL_WM_SetCaption("2048", NULL);

	return w;
}

void delete_window(window w){
	SDL_FreeSurface(w->screen);
	free(w);
}

dir move_event(window w, grid g){

	while(1){
		SDL_WaitEvent(&(w->event)); 

	    switch(w->event.type) 
	    {
	        case SDL_QUIT: 
	        	delete_window(w);
	        	delete_grid(g);
	        	//TTF_Quit(); Pour écrire le score
	            SDL_Quit();
	            exit(EXIT_SUCCESS);
	            break;

	        case SDL_KEYUP:
	        	switch(w->event.key.keysym.sym)
	        	{
	        		case SDLK_UP :
	        			return UP;
	        			break;
	        		case SDLK_DOWN :
	        			return DOWN;
	        			break;
	        		case SDLK_RIGHT :
	        			return RIGHT;
	        			break;
	        		case SDLK_LEFT :
	        			return LEFT;
	        			break;
	        		default :
	        			break;
	        	}
	        	break;

	        default :
	        	break;
	    }
	}
}

void display_screen(window w, grid g){

	SDL_FillRect(w->screen, NULL, SDL_MapRGB(w->screen->format, 70, 70, 70));
	SDL_Rect coord;
	coord.x = 30;
	coord.y = 30;
	SDL_Surface* img;
	char* str = malloc(sizeof(char) * 20);

	for(int j = 0; j < GRID_SIDE; j++){
		for(int i = 0; i < GRID_SIDE; i++){
			sprintf(str, "../img/%d.png",(int) pow(2,get_tile(g, i, j)));
			img = IMG_Load(str);
			SDL_BlitSurface(img, NULL, w->screen, &coord);
			SDL_FreeSurface(img);
			coord.x += TAILLE_CASE + TAILLE_ESPACE_ENTRE_CASE;
		}
		coord.x = 30;
		coord.y += TAILLE_CASE + TAILLE_ESPACE_ENTRE_CASE;
	}

	free(str);
	SDL_Flip(w->screen);
}



