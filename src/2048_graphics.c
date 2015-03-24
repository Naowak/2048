#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "grid.h"
#include "graphics.h"

int main(){

	initializeRandom();	
	grid g = new_grid();
	window w = new_window();

	bool win = false;
	dir d;

	display_screen(w, g);
	
	while(!game_over(g)){

		d = move_event(w, g);
		play(g, d);
		display_screen(w, g);

		if(grid_max_tile(g) == 2048 && !win){
			printf("\n\n BRAVO, UNE DE VOS CASE EST EGALE A 2048, VOUS AVEZ GAGNE\n\n");
			win = true;
		}
	}

	delete_window(w);
	delete_grid(g);
	TTF_Quit(); 
    SDL_Quit();

}


