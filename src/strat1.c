#include "strategy.h"
#include "stdlib.h"
#include <assert.h>
#include <time.h>

void free_memless_strat (strategy strat)
{
  free (strat);
}

static int rando(int a, int b){
	return rand()%(b-a) +a;
}

dir strat(strategy s, grid g){
	srand(time(NULL));
	int r = rando(0, 4);
	dir d;
	do{
		switch(r){
			case 0 : d = UP;
				break;
			case 1 : d = DOWN;
				break;
			case 2 : d = LEFT;
				break;
			case 3 : d = RIGHT; 
		}
	}while(!can_move(g, d));
	return d;
}

strategy strat1(){
	strategy s = malloc(sizeof(*s));
	assert(s != NULL);
	// s->mem = malloc(0);
	s->name = "PirroneSauzetBendi-Ouis";
	s->play_move = strat;
	s->free_strategy = free_memless_strat;
	return s;
}