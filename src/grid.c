#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "grid.h"

struct grid_s{
	tile tab[GRID_SIDE][GRID_SIDE];
};

static int random(int a, int b){
	return rand()%(b-a) +a;
}

void add_tile(grid g){
	int i = -1;
	int j = -1;
	while(i == -1 && j == -1){
		i = random(0, GRID_SIDE);
		j = random(0, GRID_SIDE);
		if(g->tab[i][j] != 0){
			i = -1;
			j = -1;
		}

	}

	int nb = random(0, 6);
	switch(nb){
		case 5 : 
			g->tab[i][j] = 2;
			break;

		default : 
			g->tab[i][j] = 1;
	}
}

grid new_grid(){

	grid g = malloc(sizeof(*g));
	assert(g != NULL);
	for (int i = 0; i < GRID_SIDE; i++)
		for (int j = 0; j < GRID_SIDE; j++)
			g->tab[i][j] = 0;


	add_tile(g);
	add_tile(g);

}

void delete_grid(grid g){
	free(g);
}

void copy_grid(grid src, grid dst){
	for (int i = 0; i < GRID_SIDE; i++)
		for (int j = 0; j < GRID_SIDE; j++)
			dst->tab[i][j] = src->tab[i][j];
}

unsigned long int grid_score(grid g){
	unsigned long int max = 0;

	for (int i = 0; i < GRID_SIDE; i++)
		for (int j = 0; j < GRID_SIDE; j++)
			if(g->tab[i][j]>max)
				max = g->tab[i][j];

	return max;
}

tile get_tile(grid g, int x, int y){
	return g->tab[x][y];
}

void set_tile(grid g, int x, int y, tile t){
	g->tab[x][y] = t;
}

bool game_over(grid g){
	if(!can_move(g, UP) && !can_move(g, DOWN) && !can_move(g, LEFT) && !can_move(g, RIGHT))
		return true;

	return false;
}


// bool can_move(grid g, dir d){
// 	switch(d){
// 		case UP : 

// 	}
// }

