/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:20:13 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 20:38:26 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

static void		getmappos(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			e->map[i][j].pos_x = j * e->w_quarter;
			e->map[i][j].pos_y = i * e->h_quarter;
			e->map[i][j].merged = 0;
			j++;
		}
		i++;
	}
}

static void		resizehook(t_env *env)
{
	clear();
	getmaxyx(stdscr, env->height, env->width);
	if (env->height < 9 || env->width < 34)
	{
		clear();
		printw("Size is too small !");
		refresh();
	}
	env->h_quarter = (int)((env->height - 1) / 4);
	env->w_quarter = (int)((env->width - 1) / 4);
	getmappos(env);
	drawmap(env);
	refresh();
}

/*
** Constantly update grid infos relative to window size
*/

void			perma_update(t_env *env)
{
	int	x;
	int	y;

	clear();
	getmaxyx(stdscr, y, x);
	if (y != env->height || x != env->width)
		resizehook(env);
	else
	{
		env->h_quarter = (int)((env->height - 1) / 4);
		env->w_quarter = (int)((env->width - 1) / 4);
		getmappos(env);
		drawmap(env);
		refresh();
	}
}
