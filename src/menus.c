#include "wong_kar_wai.h"

bool print_start_menu(void)
{
	bool play = true;
	int lines = LINES - (LINES - 1) % GRID_SIZE;
	int cols = COLS - (COLS - 1) % GRID_SIZE;
	attron(A_BLINK);
	WINDOW *w = subwin(stdscr, lines / 2 + 1, cols / 2 + 1, lines / 2 - lines / 4, cols / 2 - cols / 4);
	werase(w);
	box(w, ACS_VLINE, ACS_HLINE);
	int x = cols / 2 - ft_strlen(play_msg) / 2;
	int y = lines / 2;
	mvprintw(y, x, play_msg);
	wrefresh(w);
	int key = getch();
	if (key == 27)
	{
		attroff(A_UNDERLINE | A_BLINK);
		delwin(w);
		play = false;
		return (play);
	}
	attroff(A_UNDERLINE | A_BLINK);
	delwin(w);
	return (play);
}

WINDOW *draw_msg_box(char *msg)
{
	attroff(A_BLINK);
	int lines = LINES - (LINES - 1) % GRID_SIZE;
	int cols = COLS - (COLS - 1) % GRID_SIZE;
	WINDOW *w = subwin(stdscr,
					   lines / 2 + 1,
					   cols / 2 + 1,
					   lines / 2 - lines / 4,
					   cols / 2 - cols / 4);
	wattron(w, A_BLINK);
	werase(w);
	box(w, ACS_VLINE, ACS_HLINE);
	int x = cols / 4 - ft_strlen(msg) / 2;
	int y = lines / 4;
	mvwprintw(w, y, x, msg);
	wrefresh(w);
	return (w);
}

int you_lose(t_rect *board, bool already_won)
{

	WINDOW *w;

	if (already_won)
		w = draw_msg_box(end_msg);
	else
		w = draw_msg_box(lose_msg);

	int key;
	while ((key = getch()))
	{
		if (key == 27 || key == 'q')
		{
			delwin(w);
			return (0);
		}
		else if (key == KEY_RESIZE)
		{
			delwin(w);
			resize(board);
			if (already_won)
				w = draw_msg_box(end_msg);
			else
				w = draw_msg_box(lose_msg);
		}
	}
	delwin(w);
	return (0);
}

bool you_win(t_rect *board, bool *already_won)
{
	bool continue_playing = false;
	if (*already_won == true)
	{
		continue_playing = true;
		return (continue_playing);
	}
	WINDOW *w = draw_msg_box(win_msg);
	int key;
	while ((key = getch()))
	{
		if (key == 27 || key == 'q')
		{
			continue_playing = false;
			delwin(w);
			attroff(A_BLINK);
			return (continue_playing);
		}
		else if (key == 'c')
		{
			continue_playing = true;
			*already_won = true;
			werase(w);
			delwin(w);
			attroff(A_BLINK);
			resize(board);
			return (continue_playing);
		}
		else if (key == KEY_RESIZE)
		{
			delwin(w);
			resize(board);
			w = draw_msg_box(win_msg);
		}
	}
	attroff(A_BLINK);
	delwin(w);
	return (continue_playing);
}