/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:19:05 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 19:25:39 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

static void	try_merge_values(t_map *a, t_map *b, int *has_moved, t_env *e)
{
	if (a->value != 0 && a->value == b->value && a->merged == 0 &&
		b->merged == 0)
	{
		a->value = a->value * 2;
		a->merged = 1;
		b->value = 0;
		*has_moved = 1;
		if (a->value == WIN_VALUE)
			e->win = 1;
	}
}

static void	try_swap_values(t_map *a, t_map *b, int *has_moved)
{
	if (a->value == 0 && b->value != 0)
	{
		a->value = b->value;
		a->merged = b->merged;
		b->value = 0;
		*has_moved = 1;
	}
}

/*
** Checks if grid values can move in given position
*/

void		move_checker(t_map *a, t_map *b, int *has_moved, t_env *e)
{
	try_swap_values(a, b, has_moved);
	try_merge_values(a, b, has_moved, e);
}
