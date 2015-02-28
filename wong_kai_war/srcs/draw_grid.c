/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:07:36 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/28 17:19:57 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

/*void	ft_draw_loop(int px, int py, int nx, int ny, WINDOW *field)
{
	getmaxyx(stdscr, ny, nx);
	if (ny != py || nx != px)
		{
			px = nx;
			py = ny;
			wresize(field, ny, nx);
			wclear(stdscr);
			wclear(field);
			draw_borders(field);
		}
	wrefresh(field);
}*/

void	draw_top_and_bottom(WINDOW *screen, int x, int y, int i)
{
	while (i < (x - 1))
	{
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
		mvwprintw(screen, y/4, i, "-");
		mvwprintw(screen, (y/4)*2, i, "-");
		mvwprintw(screen, (y/4)*3, i, "-");
		i++;
	}
}

void	draw_sides(WINDOW *screen, int x, int y, int i)
{
	while (i < (y - 1))
	{
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
		mvwprintw(screen, i, x/4, "|");
		mvwprintw(screen, i, (x/4)*2, "|");
		mvwprintw(screen, i, (x/4)*3, "|");
		i++;
	}
}

void	draw_corners(WINDOW *screen, int x, int y)
{
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
}

void	draw_borders(WINDOW *screen)
{
	int	x;
	int	y;
	int	i;

	getmaxyx(screen, y, x);
	draw_corners(screen, x, y);
	i = 1;
	draw_sides(screen, x, y, i);
	i = 1;
	draw_top_and_bottom(screen, x, y, i);
}

void	ft_draw_grid(void)
{
	int parent_x;
	int parent_y;
	int new_x;
	int new_y;

	getmaxyx(stdscr, parent_y, parent_x);
	WINDOW *field = newwin(parent_y, parent_x, 0, 0);
	draw_borders(field);
	while(1)
	{	
		getmaxyx(stdscr, new_y, new_x);
	if (new_y != parent_y || new_x != parent_x)
		{
			parent_x = new_x;
			parent_y = new_y;
			wresize(field, new_y, new_x);
			wclear(stdscr);
			wclear(field);
			draw_borders(field);
		}
	wrefresh(field);
		//ft_draw_loop(parent_x, parent_y, new_x, new_y, field);
	}
	delwin(field);
	endwin();
}