#include "wong_kar_wai.h"

int main(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	define_color();

	t_rect board[GRID_SIZE * GRID_SIZE];
	int lines = LINES - (LINES - 1) % GRID_SIZE;
	int cols = COLS - (COLS - 1) % GRID_SIZE;
	if (!print_start_menu())
	{
		endwin();
		return (EXIT_SUCCESS);
	}
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			init_square_params(&board[x + y * GRID_SIZE],
							   cols / GRID_SIZE,
							   lines / GRID_SIZE,
							   x * (cols / GRID_SIZE),
							   y * (lines / GRID_SIZE));
			create_box(&board[x + y * GRID_SIZE], TRUE);
		}
	}
	generate_number(board);
	generate_number(board);
	refresh();
	game_loop(board);
	endwin();
	return (EXIT_SUCCESS);
}
