#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include "grid.h"

struct grid_s{
	tile tab[GRID_SIDE][GRID_SIDE];
};

static int random(int a, int b){
	srand(time(NULL));
	return rand()%(b-a) +a;
}

void add_tile(grid g){
	int i = -1;
	int j = -1;

	//Selection de la case à modifier 
	while(i == -1 && j == -1){
		i = random(0, GRID_SIDE);
		j = random(0, GRID_SIDE);
		if(g->tab[i][j] != 0){
			i = -1;
			j = -1;
		}
	}
	//Definition de la valeur de la case
	int nb = random(0, 9);
	switch(nb){
		case 9 : 
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

	return g;
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

bool can_move(grid g, dir d){
	switch(d){
		case UP : 
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = 0; j < GRID_SIDE - 1; j++)
					if(g->tab[i][j+1] != 0 && (g->tab[i][j] == g->tab[i][j+1] || g->tab[i][j] == 0))
						return true;
			break;

		case DOWN :
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = GRID_SIDE - 1; j > 0; j--)
					if(g->tab[i][j-1] != 0 && (g->tab[i][j] == g->tab[i][j-1] || g->tab[i][j] == 0))
						return true;
			break;

		case RIGHT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = GRID_SIDE - 1; i > 0; i--)
					if(g->tab[i-1][j] != 0 && (g->tab[i][j] == g->tab[i-1][j] || g->tab[i][j] == 0))
						return true;
			break;

		case LEFT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = 0; i < GRID_SIDE - 1; i++)
					if(g->tab[i+1][j] != 0 && (g->tab[i][j] == g->tab[i+1][j] || g->tab[i][j] == 0))
						return true;
	}
	return false;
}

bool game_over(grid g){
	if(!can_move(g, UP) && !can_move(g, DOWN) && !can_move(g, LEFT) && !can_move(g, RIGHT))
		return true;

	return false;
}

static void decalageRecursion(grid g, dir d, int i, int j){
	switch(d){
		case UP :
			if(j > 0 && g->tab[i][j-1] == 0){
				g->tab[i][j-1] = g->tab[i][j];
				g->tab[i][j] = 0;
				decalageRecursion(g, d, i, j-1);
			}
			break;
		case DOWN :
			if(j < GRID_SIDE-1 && g->tab[i][j+1] == 0){
				g->tab[i][j+1] = g->tab[i][j];
				g->tab[i][j] = 0;
				decalageRecursion(g, d, i, j+1);
			}
			break;
		case LEFT :
			if(i > 0 && g->tab[i-1][j] == 0){
				g->tab[i-1][j] = g->tab[i][j];
				g->tab[i][j] = 0;
				decalageRecursion(g, d, i-1, j);
			}
			break;
		case RIGHT :
			if(i < GRID_SIDE - 1 && g->tab[i+1][j] == 0){
				g->tab[i+1][j] = g->tab[i][j];
				g->tab[i][j] = 0;
				decalageRecursion(g, d, i+1, j);
			}
		}
}

static void additionSelonMouvement(grid g, dir d){
	switch(d){
		case UP :
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = 0; j < GRID_SIDE-1; j++)
					if(g->tab[i][j] != 0 && g->tab[i][j] == g->tab[i][j+1]){
						g->tab[i][j] += 1;
						g->tab[i][j+1] = 0;
						j++;
					}
			break;
		case DOWN :
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = GRID_SIDE-1; j > 0; j--)
					if(g->tab[i][j] != 0 && g->tab[i][j] == g->tab[i][j-1]){
						g->tab[i][j] += 1;
						g->tab[i][j-1] = 0;
						j--;
					}
			break;
		case RIGHT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = GRID_SIDE-1; i > 0; i--)
					if(g->tab[i][j] != 0 && g->tab[i][j] == g->tab[i-1][j]){
						g->tab[i][j] += 1;
						g->tab[i-1][j] = 0;
						i--;
					}
			break;
		case LEFT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = 0; i < GRID_SIDE - 1; i++)
					if(g->tab[i][j] != 0 && g->tab[i][j] == g->tab[i+1][j]){
						g->tab[i][j] += 1;
						g->tab[i+1][j] = 0;
						i++;
					}
	}
}

static void decalage(grid g, dir d){
	switch(d){
		case UP :
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = 1; j < GRID_SIDE; j++)
					decalageRecursion(g, d, i, j);
			break;
		case DOWN :
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = GRID_SIDE-2; j >= 0; j--)
					decalageRecursion(g, d, i, j);
			break;
		case RIGHT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = GRID_SIDE-2; i >= 0; i--)
					decalageRecursion(g, d, i, j);
			break;
		case LEFT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = 1; i < GRID_SIDE; i++)
					decalageRecursion(g, d, i, j);
	}
}

void do_move(grid g, dir d){
	decalage(g, d);
	additionSelonMouvement(g, d);
	decalage(g, d);
}



void display_grid(grid g){
	//system("clear");
	for (int j = 0; j < GRID_SIDE; j++){
		for (int i = 0; i < GRID_SIDE; i++){
			printf("| %d ", get_tile(g, i, j) == 0 ? 0 : (int)pow(2, get_tile(g, i, j)));
			if(i ==  GRID_SIDE-1)
				printf("|\n");
		}
	}
}
