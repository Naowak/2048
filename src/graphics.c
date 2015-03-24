#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <assert.h>
#include <math.h>
#include "grid.h"
#include "graphics.h"

int TAILLE_CASE = 70;
int TAILLE_ESPACE_ENTRE_CASE = 5;
int TAILLE_X_SCORE = 200;
int TAILLE_Y_SCORE = 120;
int TAILLE_ESPACE = 30;

struct window_s{
	int size_w;
	int size_h;
	SDL_Surface *screen;
	SDL_Event event;
};

window new_window(){
	
	window w = malloc(sizeof(*w));
	assert(w != NULL);

	w->size_w = TAILLE_CASE*GRID_SIDE + TAILLE_ESPACE_ENTRE_CASE*(GRID_SIDE - 1) + TAILLE_ESPACE*3+ TAILLE_X_SCORE;
	w->size_h = TAILLE_CASE*GRID_SIDE + TAILLE_ESPACE_ENTRE_CASE*(GRID_SIDE - 1) + 60;

	assert(SDL_Init(SDL_INIT_VIDEO) != -1);
	assert(TTF_Init() != -1);

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
	        	TTF_Quit();
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

static void img_display(window w, SDL_Surface* img, SDL_Rect coord, char* str){
	img = IMG_Load(str);
	SDL_BlitSurface(img, NULL, w->screen, &coord);
	SDL_FreeSurface(img);
}

static void text_display(window w, SDL_Surface* texte, SDL_Color couleur, SDL_Rect coord, char* str, char* police){
	TTF_Font* Police =TTF_OpenFont(police, 30);
	texte = TTF_RenderText_Blended(Police, str, couleur);
    SDL_BlitSurface(texte, NULL, w->screen, &coord);

    TTF_CloseFont(Police);
    SDL_FreeSurface(texte);
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
			img_display(w, img, coord, str);
			coord.x += TAILLE_CASE + TAILLE_ESPACE_ENTRE_CASE;
		}
		coord.x = 30;
		coord.y += TAILLE_CASE + TAILLE_ESPACE_ENTRE_CASE;
	}

	display_score(w, g);

	free(str);
	SDL_Flip(w->screen);
}


void display_score(window w, grid g){
	SDL_Rect coord;
	SDL_Surface* img;
	char* str = malloc(sizeof(char) * 10);
	char* police = "../img/dk_butterfly.otf";
	SDL_Color couleurNoire = {0, 0, 0};

	coord.x = w->size_w - TAILLE_X_SCORE - TAILLE_ESPACE;
	coord.y = 30;
	img_display(w, img, coord, "../img/score.png");

	coord.x += 20;
	coord.y += 20;
	text_display(w, img, couleurNoire, coord, "Score :",  police);

	coord.y += 40;
	sprintf(str, "%d",	(int) grid_score(g));
	text_display(w, img, couleurNoire, coord, str, police);

    free(str);
}


