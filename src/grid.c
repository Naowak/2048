#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include <time.h>

struct grid_s{
	tile tab[GRID_SIDE][GRID_SIDE];

};

static int rand(int a, int b){
	return rand()%(b-a) +a;
}

static void generateTile(){
	int i = -1;
	int j = -1;
	while(i == -1 && j == -1){
		i = rand(0, GRID_SIDE);
		j = rand(0, GRID_SIDE);
		if(tab[i][j] != 0){
			i = -1;
			j = -1;
		}

	}

	int nb = rand(0, 6);
	switch(nb){
		case 5 : 
			tab[i][j] = 2;
			break;

		default : 
			tab[i][j] = 1;
	}
}

grid new grid(){

	for (int i = 0; i < GRID_SIDE; i++)
		for (int j = 0; j < GRID_SIDE; j++)
			tab[i][j] = 0;


	generateTile();
	generateTile();


}

