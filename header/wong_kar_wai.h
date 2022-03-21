#ifndef WONG_KAR_WAI_H
#define WONG_KAR_WAI_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

#define play_msg "Press any key to start new game"
#define lose_msg "You lose - press 'q' to quit"
#define win_msg "You win - press 'q' to quit or 'c' to continue"
#define end_msg "End of game - press 'q' to quit"

enum e_const
{
	WIN_VALUE = 2048
};

enum e_color
{
	EMPTY_COLOR = 8,
	BORDER_COLOR,
	FILL_COLOR_2 = 10,
	FILL_COLOR_4,
	FILL_COLOR_8,
	FILL_COLOR_16,
	FILL_COLOR_32,
	FILL_COLOR_64,
	FILL_COLOR_128,
	FILL_COLOR_256,
	FILL_COLOR_512,
	FILL_COLOR_1024,
	FILL_COLOR_2048,
	FILL_COLOR_4096
};
enum e_pair
{
	EMPTY_PAIR = 1,
	BORDER_PAIR,
	FILL_PAIR_2,
	FILL_PAIR_4,
	FILL_PAIR_8,
	FILL_PAIR_16,
	FILL_PAIR_32,
	FILL_PAIR_64,
	FILL_PAIR_128,
	FILL_PAIR_256,
	FILL_PAIR_512,
	FILL_PAIR_1024,
	FILL_PAIR_2048,
	FILL_PAIR_4096
};

typedef struct _win_border_struct
{
	chtype ls, rs, ts, bs, tl, tr, bl, br;
} WIN_BORDER;

typedef struct s_rect
{
	unsigned int posx;
	unsigned int posy;
	unsigned int width;
	unsigned int height;
	unsigned int value;
	WIN_BORDER border;
} t_rect;


// Utils
size_t ft_strlen(char *str);
int ft_digitlen(unsigned int nbr);
void putnbr_ascii(unsigned int nbr, int x, int y);
void define_color();

// Move
bool can_move_up(t_rect *board);
bool can_move_down(t_rect *board);
bool can_move_left(t_rect *board);
bool can_move_right(t_rect *board);
void move_up(t_rect *board);
void move_down(t_rect *board);
void move_left(t_rect *board);
void move_right(t_rect *board);

// Menu
bool print_start_menu(void);
WINDOW *draw_msg_box(char *msg);
int you_lose(t_rect *board, bool already_won);
bool you_win(t_rect *board, bool *already_won);

// Box
void create_box(t_rect *p_rect, bool flag);
void wupdate_rect_value(t_rect *rect, int val);
void init_square_params(t_rect *p_rect, int width, int height, int posx, int posy);

// Game
int gradient(unsigned int nbr);
void resize(t_rect *board);
void generate_number(t_rect *board);
bool check_win(t_rect *board);
int game_loop(t_rect *board);

#endif
