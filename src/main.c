#include "wong_kar_wai.h"
#include <ncurses.h>
#include <stdlib.h>

int main(void) {
	initscr(); // Init struct WINDOW

	t_square board[GRID_SIZE][GRID_SIZE];

	// LINES -= LINES % GRID_SIZE;
	// COLS -= COLS % GRID_SIZE;
	printw("\n%d cols\n", COLS);
	printw("%d lines\n", LINES);
	refresh(); //

	// create a sub window for each square
	for (int x = 0; x < GRID_SIZE; ++x) {
		for (int y = 0; y < GRID_SIZE; ++y) {
			board[x][y].posx   = x * (LINES / GRID_SIZE);
			board[x][y].posy   = y * (COLS / GRID_SIZE);
			board[x][y].width  = LINES / GRID_SIZE + 1;
			board[x][y].height = COLS / GRID_SIZE + 1;
			board[x][y].win	   = subwin(stdscr,
										board[x][y].width,
										board[x][y].height,
										board[x][y].posx,
										board[x][y].posy);
		}
	}

	// draw border for each square and refresh screen
	for (int x = 0; x < GRID_SIZE; ++x) {
		for (int y = 0; y < GRID_SIZE; ++y) {
			box(board[x][y].win, ACS_VLINE, ACS_HLINE);
			wrefresh(board[x][y].win);
		}
	}

	getch(); // Wait for user input any key to quit

	// delete each sub window
	for (int x = 0; x < GRID_SIZE; ++x) {
		for (int y = 0; y < GRID_SIZE; ++y) {
			delwin(board[x][y].win);
		}
	}
	endwin(); // Delete main window
	return (EXIT_SUCCESS);
}
