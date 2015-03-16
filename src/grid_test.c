#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include <string.h>
// #include <SDL2/SDL.h>

static bool validDir(char d[2]){
	if(strcmp(d, "up") == 0 || strcmp(d, "do")== 0 || strcmp(d, "ri")== 0 || strcmp(d, "le")== 0)
		return true;
	return false;
}

int main(){
	//Initialisation de la SDL

	// SDL_Window* fenetre(0);

	// if(SDL_INIT(SDL_INIT_VIDEO) < 0){
	// 	printf("Erreur lors de l'initialisation de la SDL\n");
	// 	SDL_Quit();

	// 	return EXIT_FAILURE;
	// }

	//Création de la fenêtre

	// fenetre = SDL_CreateWindow("2048" SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	grid g = new_grid();
	display_grid(g);
	char d[2] = "nu";
	initializeRandom();	
	
	while(!game_over(g)){
		scanf("%2s", d);
		while(!validDir(d)){
			printf("\ndirection <up, do, le, ri> : ");
			scanf("%2s", d);
		}

		if(strcmp(d, "up")== 0){
			play(g, UP);
		}
		else if(strcmp(d, "do")== 0){
			play(g, DOWN);
		}
		else if(strcmp(d, "le")== 0){
			play(g, LEFT);
		}
		else if(strcmp(d, "ri")== 0){
			play(g, RIGHT);
		}
		printf("\nScore : %ld \n", grid_score(g));
		display_grid(g);
	}

	free_grid(g);

	// SDL_DestroyWindow(fenetre);
	// SDL_Quit();
}

