/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:27:10 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 20:35:29 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

/*
** man 3 start_color
*/

void		setcolor(void)
{
	start_color();
	if (has_colors() == FALSE)
	{
		endwin();
		printf("No colors available\n");
		exit(1);
	}
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(5, COLOR_BLACK, COLOR_CYAN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
}

/*
** 2 = white
** 4 = cyan
** 8 = green
** 16 = yellow
** 32 = magenta
** 64 = red
** 128 and + = blue
*/

int			addcolor(int value)
{
	int	color;

	setcolor();
	if (value == 2)
		color = 1;
	else if (value == 4)
		color = 5;
	else if (value == 8)
		color = 2;
	else if (value == 16)
		color = 8;
	else if (value == 32)
		color = 4;
	else if (value == 64)
		color = 3;
	else if (value > 64)
		color = 6;
	else
		color = 9;
	return (color);
}

void		color_tile(t_env *e, t_map *map)
{
	int x1;
	int	y1;
	int x2;
	int y2;

	x1 = map->pos_x + 1;
	y1 = map->pos_y + 1;
	x2 = (x1 + e->w_quarter - 1);
	y2 = (y1 + e->h_quarter - 1);
	while (y1 < y2)
	{
		x1 = map->pos_x + 1;
		while (x1 < x2)
		{
			mvaddch(y1, x1, ' ');
			x1++;
		}
		y1++;
	}
}

void		drawvalue(t_env *e, t_map *map)
{
	char	*value;
	size_t	len;
	int		i;

	value = ft_itoa(map->value);
	len = ft_strlen(value) / 2;
	i = 0;
	while (value[i] != '\0')
	{
		mvaddch(map->pos_y + e->h_quarter / 2, map->pos_x + e->w_quarter / 2 -
			(len - i), value[i]);
		i++;
	}
	free(value);
}

/*
**  Draws map from updated infos on stdscr
*/

void		drawmap(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			draw_norm_joke(e, i, j);
			if (i == 3)
				mvaddch(POS_Y + e->h_quarter, e->map[i][j].pos_x, '+');
			j++;
		}
		mvaddch(e->map[i][j - 1].pos_y,
			e->map[i][j - 1].pos_x + e->w_quarter, '+');
		i++;
	}
	mvaddch(e->map[i - 1][j - 1].pos_y + e->h_quarter,
		e->map[i - 1][j - 1].pos_x + e->w_quarter, '+');
}
