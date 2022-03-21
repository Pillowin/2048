#include "wong_kar_wai.h"

void create_box(t_rect *p_rect, bool flag)
{
	int i, j;
	int x, y, w, h;

	x = p_rect->posx;
	y = p_rect->posy;
	w = p_rect->width;
	h = p_rect->height;

	if (flag == TRUE)
	{
		attron(COLOR_PAIR(BORDER_PAIR));

		mvaddch(y, x, p_rect->border.tl);
		mvaddch(y, x + w, p_rect->border.tr);
		mvaddch(y + h, x, p_rect->border.bl);
		mvaddch(y + h, x + w, p_rect->border.br);
		mvhline(y, x + 1, p_rect->border.ts, w - 1);
		mvhline(y + h, x + 1, p_rect->border.bs, w - 1);
		mvvline(y + 1, x, p_rect->border.ls, h - 1);
		mvvline(y + 1, x + w, p_rect->border.rs, h - 1);
		attroff(COLOR_PAIR(BORDER_PAIR));

		if (p_rect->value > 0)
		{
			attron(COLOR_PAIR(FILL_PAIR_2 + gradient(p_rect->value)));
			for (j = y + 1; j < y + h; ++j)
				for (i = x + 1; i < x + w; ++i)
					mvaddch(j, i, ' ');
			putnbr_ascii(p_rect->value, x + w / 2 - ft_digitlen(p_rect->value) * 3 / 2, y + h / 2 - 1);
			attroff(COLOR_PAIR(FILL_PAIR_2 + gradient(p_rect->value)));
		}
		else
		{
			attron(COLOR_PAIR(EMPTY_PAIR));
			for (j = y + 1; j < y + h; ++j)
				for (i = x + 1; i < x + w; ++i)
					mvaddch(j, i, ' ');
			attroff(COLOR_PAIR(EMPTY_PAIR));
		}
	}
	else
	{
		attron(COLOR_PAIR(EMPTY_PAIR));

		for (j = y + 1; j < y + h; ++j)
			for (i = x + 1; i < x + w; ++i)
				mvaddch(j, i, ' ');
		p_rect->value = 0;
		attroff(COLOR_PAIR(EMPTY_PAIR));
	}
	refresh();
}

void wupdate_rect_value(t_rect *rect, int val)
{
	create_box(rect, FALSE);
	rect->value = val;
	putnbr_ascii(val, rect->posx + rect->width / 2 - ft_digitlen(val) * 3 / 2, rect->posy + rect->height / 2 - 2);
}

void init_square_params(t_rect *p_rect, int width, int height, int posx, int posy)
{
	p_rect->height = height;
	p_rect->width = width;
	p_rect->posx = posx;
	p_rect->posy = posy;
	p_rect->value = 0;

	p_rect->border.ls = '|';
	p_rect->border.rs = '|';
	p_rect->border.ts = '-';
	p_rect->border.bs = '-';
	p_rect->border.tl = '+';
	p_rect->border.tr = '+';
	p_rect->border.bl = '+';
	p_rect->border.br = '+';
}

