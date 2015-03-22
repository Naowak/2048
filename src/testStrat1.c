#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include <string.h>
#include <time.h>


int number_of_empty_cells_after_moves(grid g, dir d){
	grid copy = new_grid();
	copy_grid(g, copy);

	do_move(copy, d);
	if(can_move(copy, UP))
		do_move(copy, UP);

	int nb = 0;
	for(int i = 0 ; i < GRID_SIDE ; i++)
		for(int j = 0 ; j < GRID_SIDE ; j++)
			if(get_tile(copy, i, j) == 0)
				nb++;

	delete_grid(copy);
	return nb;

}

int main(){
	grid g = new_grid();
	display_grid(g);
	while( !game_over(g) ) {
		dir d = UP;
	    if( !can_move(g, UP) ) {
	        if( can_move(g, RIGHT) && can_move(g, LEFT) ){
	            if( number_of_empty_cells_after_moves(g, LEFT) > number_of_empty_cells_after_moves(g, RIGHT) ) 
	                d = LEFT;
	            else
	                d = RIGHT;
	        } else if ( can_move(g, LEFT) ){
	            d = LEFT;
	        } else if ( can_move(g, RIGHT) ){
	            d = RIGHT;
	        } else {
	            d = DOWN;
	        }
	    }
	    play(g, d);
	    display_grid(g);
	}


	delete_grid(g);
}



