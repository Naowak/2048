#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "grid.h"

struct grid_s{
	tile tab[GRID_SIDE][GRID_SIDE];

};

static int rand(int a, int b){
	return rand()%(b-a) +a;
}

static void generateTile(grid g){
	int i = -1;
	int j = -1;
	while(i == -1 && j == -1){
		i = rand(0, GRID_SIDE);
		j = rand(0, GRID_SIDE);
		if(g->tab[i][j] != 0){
			i = -1;
			j = -1;
		}

	}

	int nb = rand(0, 6);
	switch(nb){
		case 5 : 
			g->tab[i][j] = 2;
			break;

		default : 
			g->tab[i][j] = 1;
	}
}

grid new grid(){

	grid g = malloc(sizeof(*g));
	assert(g != null);
	for (int i = 0; i < GRID_SIDE; i++)
		for (int j = 0; j < GRID_SIDE; j++)
			g->tab[i][j] = 0;


	generateTile(g);
	generateTile(g);

}

void deleteGrid(grid g){
	free g;
}

void copy_grid(grid src, grid dst){
	for (int i = 0; i < GRID_SIDE; i++)
		for (int j = 0; j < GRID_SIDE; j++)
			dst->tab[i][j] = grid[i][j];
}

