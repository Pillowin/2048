#include "wong_kar_wai.h"

int game_loop(t_rect *board)
{
	int key;
	static bool already_won = false;
	while ((key = getch()))
	{
		if (key == 27)
			return (0);
		else if (key == KEY_UP && can_move_up(board))
			move_up(board);
		else if (key == KEY_DOWN && can_move_down(board))
			move_down(board);
		else if (key == KEY_LEFT && can_move_left(board))
			move_left(board);
		else if (key == KEY_RIGHT && can_move_right(board))
			move_right(board);
		else if (key == KEY_RESIZE)
		{
			resize(board);
			continue;
		}
		else
			continue;

		generate_number(board);
		attron(A_BLINK);
		if (!can_move_up(board) && !can_move_down(board) && !can_move_left(board) && !can_move_right(board))
			return (you_lose(board, already_won));
		if (check_win(board))
			if (!you_win(board, &already_won))
				return (0);
		attroff(A_BLINK);
		refresh();
	}
	return (0);
}

int gradient(unsigned int nbr)
{
	int i;
	for (i = 0; nbr != 2; ++i)
		nbr >>= 1;
	return (i > 10 ? 10 : i);
}


void resize(t_rect *board)
{
	int lines = LINES - (LINES - 1) % GRID_SIZE;
	int cols = COLS - (COLS - 1) % GRID_SIZE;
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int rect = y * GRID_SIZE + x;
			board[rect].height = lines / GRID_SIZE;
			board[rect].width = cols / GRID_SIZE;
			board[rect].posx = board[rect].width * x;
			board[rect].posy = board[rect].height * y;
		}
	}
	erase();
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
		create_box(&board[i], TRUE);
}


void generate_number(t_rect *board)
{
	int cell;

	srand(time(NULL));
	cell = rand() % (GRID_SIZE * GRID_SIZE);
	while (board[cell].value)
		cell = rand() % (GRID_SIZE * GRID_SIZE);

	int random = rand() % 5;
	if (!random)
		wupdate_rect_value(&board[cell], 4);
	else
		wupdate_rect_value(&board[cell], 2);
	create_box(&board[cell], TRUE);
}

bool check_win(t_rect *board)
{
	unsigned int win_value = 2048;
	if (WIN_VALUE != 0 && ((WIN_VALUE & (WIN_VALUE - 1)) == 0))
		win_value = WIN_VALUE;
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
		if (board[i].value == win_value)
			return (true);
	return (false);
}
