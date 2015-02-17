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
				for(int j = 0; j < GRID_SIDE - 1; j ++)
					if(g->tab[i][j] == g->tab[i][j+1] || (g->tab[i][j] == 0 && g->tab[i][j+1]))
						return true;
			break;

		case DOWN :
			for(int i = 0; i < GRID_SIDE; i++)
				for(int j = GRID_SIDE - 1; j > 0; j--)
					if(g->tab[i][j] == g->tab[i][j-1] || (g->tab[i][j] == 0 && g->tab[i][j-1]))
						return true;
			break;

		case RIGHT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = GRID_SIDE - 1; i > 0; i--)
					if(g->tab[i][j] == g->tab[i-1][j] || (g->tab[i][j] == 0 && g->tab[i-1][j]))
						return true;
			break;

		case LEFT :
			for(int j = 0; j < GRID_SIDE; j++)
				for(int i = 0; i < GRID_SIDE - 1; i ++)
					if(g->tab[i][j] == g->tab[i+1][j] || (g->tab[i][j] == 0 && g->tab[i+1][j]))
						return true;
	return false;
	}
}

bool game_over(grid g){
	if(!can_move(g, UP) && !can_move(g, DOWN) && !can_move(g, LEFT) && !can_move(g, RIGHT))
		return true;

	return false;
}

void do_move(grid g, dir d){
	switch(d){
		case UP :
			for (int i = 0; i < GRID_SIDE; i++)
				for (int j = 0; j < GRID_SIDE - 1; j++)
				{
					if(g->tab[i][j] == 0){
						int k = j + 1;
						while(k != GRID_SIDE){
							if(g->tab[i][k] == 0)
								k++;
							else{
								g->tab[i][j] = g->tab[j][k];
								g->tab[j][k] = 0;
								break;
							}
						}
					}
					else if(g->tab[i][j] == g->tab[i][j+1]){
						g->tab[i][j] += 1;
						g->tab[i][j+1] = 0;
					}
				}
			break;

		case DOWN :
			for (int i = 0; i < GRID_SIDE; i++)
				for (int j = GRID_SIDE - 1; j > 0; j--)
				{
					if(g->tab[i][j] == 0){
						int k = j - 1;
						while(k != 0){
							if(g->tab[i][k] == 0)
								k--;
							else{
								g->tab[i][j] = g->tab[i][k];
								g->tab[i][k] = 0;
								break;
							}
						}
					}
					else if(g->tab[i][j] == g->tab[i][j-1]){
						g->tab[i][j] += 1;
						g->tab[i][j-1] = 0;
					}
				}
			break;

		case RIGHT :
			for (int j = 0; j < GRID_SIDE; j++)
				for (int i = GRID_SIDE - 1; i > 0; i--)
				{
					if(g->tab[i][j] == 0){
						int k = i - 1;
						while(k != 0){
							if(g->tab[k][j] == 0)
								k--;
							else{
								g->tab[i][j] = g->tab[k][j];
								g->tab[k][j] = 0;
								break;
							}
						}
					}
					else if(g->tab[i][j] == g->tab[i-1][j]){
						g->tab[i][j] += 1;
						g->tab[i-1][j] = 0;
					}
				}
			break;

		case LEFT :
			for (int j = 0; j < GRID_SIDE; j++)
				for (int i = 0; i < GRID_SIDE - 1; i++)
				{
					if(g->tab[i][j] == 0){
						int k = i + 1;
						while(k != GRID_SIDE){
							if(g->tab[k][j] == 0)
								k++;
							else{
								g->tab[i][j] = g->tab[k][j];
								g->tab[k][j] = 0;
								break;
							}
						}
					}
					else if(g->tab[i][j] == g->tab[i+1][j]){
						g->tab[i][j] += 1;
						g->tab[i+1][j] = 0;
					}
				}
	}
}

void display_grid(grid g){
	system("clear");
	for (int i = 0; i < GRID_SIDE; i++){
		for (int j = 0; j < GRID_SIDE; j++){
			printf("| %d ", get_tile(g, i, j) == 0 ? 0 : (int)pow(2, get_tile(g, i, j)));
			if(j ==  GRID_SIDE-1)
				printf("|\n");
		}
	}

}
