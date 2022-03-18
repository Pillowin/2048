#include "wong_kar_wai.h"
#include <ncurses.h>
#include <stdlib.h>

int main(void) {
	WINDOW* win = initscr(); // Init struct WINDOW

	for (int x = 0; x < GRID_SIZE; ++x) {
		for (int y = 0; y < GRID_SIZE; ++y) {
			win = subwin(stdscr,
						 LINES / GRID_SIZE,
						 COLS / GRID_SIZE,
						 x * (LINES / GRID_SIZE),
						 y * (COLS / GRID_SIZE));
			box(win, ACS_VLINE, ACS_HLINE);
		}
	}

	// printw("Actualy there are %d cols\n", COLS);	// Print at current cursor
	// positon printw("Actualy there are %d lines\n", LINES); refresh();	//
	// Draw on screen

	getch(); // Wait for user input any key to quit

	endwin(); // Reset terminal
	// free(win);
	return (EXIT_SUCCESS);
}
