#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdbool.h>
#include "grid.h"

typedef struct window_s* window;

window new_window ();
/* Initialize the SDL */

void delete_window(window w);
/* Free all the memory allocated for the window */

dir move_event (window w, grid g);
/* catch the event for the move */

void display_screen(window w, grid g);
/* display the screen */

bool rejouer_event(window w, grid g);
/* catch the event for replay a game */


#endif