/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_norm_lol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:39:44 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 20:38:38 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

void	draw_norm_joke(t_env *e, int i, int j)
{
	int color;

	mvhline(POS_Y, e->map[i][j].pos_x, '-', e->w_quarter);
	mvhline(POS_Y + e->h_quarter, e->map[i][j].pos_x, '-', e->w_quarter);
	mvvline(POS_Y, e->map[i][j].pos_x, '|', e->h_quarter);
	mvvline(POS_Y, e->map[i][j].pos_x + e->w_quarter, '|', e->h_quarter);
	mvaddch(POS_Y, e->map[i][j].pos_x, '+');
	color = addcolor(e->map[i][j].value);
	attron(COLOR_PAIR(color));
	e->map[i][j].color = color;
	color_tile(e, &(e->map[i][j]));
	drawvalue(e, &(e->map[i][j]));
	attroff(COLOR_PAIR(color));
}
