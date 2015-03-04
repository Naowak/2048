#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include <string.h>
#include <time.h>

// static bool validDir(char d[2]){
// 	if(strcmp(d, "up") == 0 || strcmp(d, "do")== 0 || strcmp(d, "ri")== 0 || strcmp(d, "le")== 0)
// 		return true;
// 	return false;
// }

static int random(int a, int b){
	return rand()%(b-a) +a;
}

int main(){
	initializeRandom();
	srand(time(NULL));
	grid g = new_grid();
	display_grid(g);
	
	while(!game_over(g)){
		int r = random(0, 4);
		printf("%d\n", r);
		switch(r){
			case 0 : play(g, UP); break;
			case 1 : play(g, DOWN); break;
			case 2 : play(g, LEFT) ; break;
			case 3 : play(g, RIGHT);
		}

		display_grid(g);
	}

	free_grid(g);
}

