#include <stdio.h>
#include <stdlib.h> 
#include "grid.h"

grid g;

int main(){
	g = new_grid();
	display_grid(g);
}