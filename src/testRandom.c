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
		switch(r){
			case 0 : play(g, UP); 
				printf("UP\n");
				break;
			case 1 : play(g, DOWN);
				printf("DOWN\n");
				break;
			case 2 : play(g, LEFT);
				printf("LEFT\n");
				break;
			case 3 : play(g, RIGHT);
				printf("RIGHT\n");
		}
	
		if(grid_max_tile(g) == 2048)
			printf("\n\n BRAVO, VOUS AVEZ ATTEINT LE SCORE DE 2048\n\n");
		printf("\nScore : %ld \n", grid_score(g));
		display_grid(g);
	}

	delete_grid(g);
}

