#include "wong_kar_wai.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		++i;
	return (i);
}

int ft_digitlen(unsigned int nbr)
{
	int i = 1;
	while (nbr > 9)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void print_ascii(unsigned int nbr, int x, int y)
{
	const char digits[10][3][4] = {
		{" _,",
		 "|.|",
		 "|_|"},
		{" , ",
		 "/| ",
		 ".|."},
		{" _,",
		 "'_)",
		 "/_."},
		{" _,",
		 "'_)",
		 "._)"},
		{". ,",
		 "|_|",
		 "  |"},
		{"._,",
		 "|_ ",
		 "._)"},
		{"._,",
		 "(_ ",
		 "(_)"},
		{"__",
		 " /",
		 "/ "},
		{" _,",
		 "(_)",
		 "(_)"},
		{" _,",
		 "(_)",
		 "  |"},
	};
	mvprintw(y, x, "%s", digits[nbr][0]);
	mvprintw(y + 1, x, "%s", digits[nbr][1]);
	mvprintw(y + 2, x, "%s", digits[nbr][2]);
}

void putnbr_ascii(unsigned int nbr, int x, int y)
{
	unsigned int digits[10];
	unsigned int d = nbr;
	int i = 0;
	while (d > 0)
	{
		digits[i] = d % 10;
		d /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		print_ascii(digits[i], x + (ft_digitlen(nbr) - i - 1) * 3, y);
		i--;
	}
}

void define_color()
{
	start_color();

	init_color(EMPTY_COLOR, 804, 757, 706);
	init_color(BORDER_COLOR, 733, 678, 627);
	init_color(FILL_COLOR_2, 933, 894, 855);
	init_color(FILL_COLOR_4, 937, 831, 800);
	init_color(FILL_COLOR_8, 941, 773, 745);
	init_color(FILL_COLOR_16, 945, 710, 690);
	init_color(FILL_COLOR_32, 953, 651, 635);
	init_color(FILL_COLOR_64, 957, 588, 580);
	init_color(FILL_COLOR_128, 961, 529, 522);
	init_color(FILL_COLOR_256, 965, 467, 467);
	init_color(FILL_COLOR_512, 969, 404, 412);
	init_color(FILL_COLOR_1024, 973, 345, 357);
	init_color(FILL_COLOR_2048, 980, 282, 302);
	init_color(FILL_COLOR_4096, 984, 224, 247);

	init_pair(EMPTY_PAIR, BORDER_COLOR, EMPTY_COLOR);
	init_pair(BORDER_PAIR, COLOR_BLACK, BORDER_COLOR);
	for (int i = FILL_PAIR_2; i < FILL_PAIR_4096; ++i)
		init_pair(i, COLOR_BLACK, FILL_COLOR_2 + i - FILL_PAIR_2);
}