#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include <string.h>

static bool validDir(char d[2]){
	if(strcmp(d, "up") == 0 || strcmp(d, "do")== 0 || strcmp(d, "ri")== 0 || strcmp(d, "le")== 0)
		return true;
	return false;
}

int main(){
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

		display_grid(g);
	}

	free_grid(g);}

