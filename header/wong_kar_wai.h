#ifndef WONG_KAR_WAI_H
#define WONG_KAR_WAI_H

#include <ncurses.h>

#define GRID_SIZE 4

typedef struct s_square {
		WINDOW*		 win;
		unsigned int posx;
		unsigned int posy;
		unsigned int width;
		unsigned int height;
		unsigned int value;
} t_square;

#endif
