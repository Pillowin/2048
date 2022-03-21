#include "wong_kar_wai.h"

bool can_move_up(t_rect *board)
{
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 1; y < GRID_SIZE; ++y)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = (y - 1) * GRID_SIZE + x;
			if (board[square].value && (!board[upper_square].value || board[square].value == board[upper_square].value))
			{
				return (true);
			}
		}
	}
	return (false);
}

bool can_move_down(t_rect *board)
{
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = GRID_SIZE - 2; y >= 0; --y)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = (y + 1) * GRID_SIZE + x;
			if (board[square].value && (!board[upper_square].value || board[square].value == board[upper_square].value))
			{
				return (true);
			}
		}
	}
	return (false);
}
bool can_move_left(t_rect *board)
{
	for (int y = 0; y < GRID_SIZE; ++y)
	{
		for (int x = 1; x < GRID_SIZE; ++x)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = y * GRID_SIZE + x - 1;
			if (board[square].value && (!board[upper_square].value || board[square].value == board[upper_square].value))
			{
				return (true);
			}
		}
	}
	return (false);
}
bool can_move_right(t_rect *board)
{
	for (int y = 0; y < GRID_SIZE; ++y)
	{
		for (int x = GRID_SIZE - 2; x >= 0; --x)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = y * GRID_SIZE + x + 1;
			if (board[square].value && (!board[upper_square].value || board[square].value == board[upper_square].value))
			{
				return (true);
			}
		}
	}
	return (false);
}

void move_up(t_rect *board)
{
	for (int y = 0; y < GRID_SIZE - 1; ++y)
	{
		for (int x = 0; x < GRID_SIZE; ++x)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = (y + 1) * GRID_SIZE + x;
			while (upper_square < GRID_SIZE * GRID_SIZE && !board[upper_square].value)
				upper_square += GRID_SIZE;
			if (upper_square >= GRID_SIZE * GRID_SIZE)
				continue;
			if (board[square].value && board[square].value == board[upper_square].value)
			{
				board[square].value <<= 1;
				create_box(&board[upper_square], false);
			}
			else if (!board[square].value)
			{
				board[square].value = board[upper_square].value;
				create_box(&board[upper_square], false);
				--x;
			}
		}
	}
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
		create_box(&board[i], true);
}

void move_down(t_rect *board)
{
	for (int y = GRID_SIZE - 1; y > 0; --y)
	{
		for (int x = 0; x < GRID_SIZE; ++x)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = (y - 1) * GRID_SIZE + x;
			while (upper_square >= x && !board[upper_square].value)
				upper_square -= GRID_SIZE;
			if (upper_square < 0)
				continue;
			if (board[square].value && board[square].value == board[upper_square].value)
			{
				board[square].value <<= 1;
				create_box(&board[upper_square], false);
			}
			else if (!board[square].value)
			{
				board[square].value = board[upper_square].value;
				create_box(&board[upper_square], false);
				--x;
			}
		}
	}
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
		create_box(&board[i], true);
}

void move_left(t_rect *board)
{
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = y * GRID_SIZE + x + 1;
			while (upper_square < GRID_SIZE * y + GRID_SIZE && !board[upper_square].value)
				upper_square += 1;
			if (upper_square >= GRID_SIZE * y + GRID_SIZE)
				continue;
			if (board[square].value && board[square].value == board[upper_square].value)
			{
				board[square].value <<= 1;
				create_box(&board[upper_square], false);
			}
			else if (!board[square].value)
			{
				board[square].value = board[upper_square].value;
				create_box(&board[upper_square], false);
				--y;
			}
		}
	}
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
		create_box(&board[i], true);
}

void move_right(t_rect *board)
{
	for (int x = GRID_SIZE - 1; x > 0; --x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int square = y * GRID_SIZE + x;
			int upper_square = y * GRID_SIZE + x - 1;
			while (upper_square - GRID_SIZE * y >= 0 && !board[upper_square].value)
				upper_square -= 1;
			if (upper_square - GRID_SIZE * y < 0)
				continue;
			if (board[square].value && board[square].value == board[upper_square].value)
			{
				board[square].value <<= 1;
				create_box(&board[upper_square], false);
			}
			else if (!board[square].value)
			{
				board[square].value = board[upper_square].value;
				create_box(&board[upper_square], false);
				--y;
			}
		}
	}
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
		create_box(&board[i], true);
}