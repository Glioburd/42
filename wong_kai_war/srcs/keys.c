/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:28:41 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 19:05:48 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

static void		movetoleft(t_env *env, int *nomove)
{
	int	i;
	int	j;
	int	can_move;
	int	has_moved;

	can_move = 1;
	while (can_move == 1)
	{
		has_moved = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 3)
			{
				move_checker(COORD, &(env->map[i][j + 1]), &has_moved, env);
				j++;
				*nomove = (has_moved == 1) ? *nomove + 1 : *nomove;
			}
			i++;
		}
		can_move = (has_moved == 1) ? 1 : 0;
	}
}

static void		movetoright(t_env *env, int *nomove)
{
	int	i;
	int	j;
	int	can_move;
	int	has_moved;

	can_move = 1;
	while (can_move == 1)
	{
		has_moved = 0;
		i = 0;
		while (i < 4)
		{
			j = 3;
			while (j > 0)
			{
				move_checker(COORD, &(env->map[i][j - 1]), &has_moved, env);
				j--;
				*nomove = (has_moved == 1) ? *nomove + 1 : *nomove;
			}
			i++;
		}
		can_move = (has_moved == 1) ? 1 : 0;
	}
}

static void		moveup(t_env *env, int *nomove)
{
	int	i;
	int	j;
	int	can_move;
	int	has_moved;

	can_move = 1;
	while (can_move == 1)
	{
		has_moved = 0;
		j = 0;
		while (j < 4)
		{
			i = 0;
			while (i < 3)
			{
				move_checker(COORD, &(env->map[i + 1][j]), &has_moved, env);
				i++;
				*nomove = (has_moved == 1) ? *nomove + 1 : *nomove;
			}
			j++;
		}
		can_move = (has_moved == 1) ? 1 : 0;
	}
}

static void		movedown(t_env *env, int *nomove)
{
	int	i;
	int	j;
	int	can_move;
	int	has_moved;

	can_move = 1;
	while (can_move == 1)
	{
		has_moved = 0;
		j = 0;
		while (j < 4)
		{
			i = 3;
			while (i > 0)
			{
				move_checker(COORD, &(env->map[i - 1][j]), &has_moved, env);
				i--;
				*nomove = (has_moved == 1) ? *nomove + 1 : *nomove;
			}
			j++;
		}
		can_move = (has_moved == 1) ? 1 : 0;
	}
}

/*
** Arrows keys actions
*/

int				movevalue(t_env *env, int key)
{
	int nomove;

	nomove = 0;
	if (key == KEY_LEFT)
		movetoleft(env, &nomove);
	else if (key == KEY_RIGHT)
		movetoright(env, &nomove);
	else if (key == KEY_UP)
		moveup(env, &nomove);
	else
		movedown(env, &nomove);
	return (nomove);
}
