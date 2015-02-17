#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"
#include <string.h>

grid g;

bool validDir(char d[2]){
	if(strcmp(d, "up") == 0 || strcmp(d, "do")== 0 || strcmp(d, "ri")== 0 || strcmp(d, "le")== 0)
		return true;
	return false;
}

int main(){
	g = new_grid();
	display_grid(g);
	char d[2] = "nu";
	
	while(!game_over(g)){
		scanf("%2s", d);
		while(!validDir(d)){
			printf("\ndirection <up, do, le, ri> : ");
			scanf("%2s", d);
		}

		if(strcmp(d, "up")== 0)
			if(can_move(g, UP))
				do_move(g, UP);
		if(strcmp(d, "do")== 0)
			if(can_move(g, DOWN))
				do_move(g, DOWN);
		if(strcmp(d, "le")== 0)
			if(can_move(g, LEFT))
				do_move(g, LEFT);
		if(strcmp(d, "ri")== 0)
			if(can_move(g, RIGHT))
				do_move(g, RIGHT);

		display_grid(g);
	}
}

