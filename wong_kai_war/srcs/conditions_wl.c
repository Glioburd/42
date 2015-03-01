/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_wl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:30:20 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 18:59:41 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

/*
** Event caused when we get WIN_VALUE
*/

void		checkwin(t_env *env)
{
	int	key;

	key = 0;
	while (key != 27 || key != 99)
	{
		clear();
		init_pair(11, COLOR_CYAN, COLOR_BLACK);
		attron(COLOR_PAIR(11));
		mvwprintw(stdscr, env->height / 2, env->width / 2 - 32, \
				"A WINNER IS YOU ! Press C to continue or ESCAPE to quit.\n");
		attroff(COLOR_PAIR(11));
		refresh();
		key = getch();
		if (key == ESCAPE_KEY)
		{
			curs_set(1);
			exit(0);
			endwin();
		}
		else if (key == C_KEY)
		{
			env->win = 0;
			return ;
		}
	}
}

static int	goleft(t_env *env, int can_move)
{
	int			i;
	int			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			if (CASE_VALUE == env->map[i + 1][j].value)
				can_move = 1;
			i++;
		}
		j++;
	}
	return (can_move);
}

static int	godown(t_env *env, int can_move)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (CASE_VALUE == env->map[i][j + 1].value)
				can_move = 1;
			j++;
		}
		i++;
	}
	return (can_move);
}

void		ft_you_lost(t_env *env)
{
	clear();
	init_pair(10, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(10));
	mvwprintw(stdscr, env->height / 2, env->width / 2 - 16, \
		"LOL YOU SUCK! Press R to restart or ESCAPE to quit.\n");
	attroff(COLOR_PAIR(10));
	refresh();
}

/*
**  Events caused if the game is blocked
*/

int			defeat_check(t_env *env)
{
	int			can_move;
	int			key;

	key = 0;
	can_move = 0;
	can_move = goleft(env, can_move);
	can_move = godown(env, can_move);
	if (can_move == 0)
	{
		while (key != 27 || key != 113)
		{
			ft_you_lost(env);
			key = getch();
			if (key == 27)
			{
				curs_set(1);
				exit(0);
				endwin();
			}
			else if (key == R_KEY)
				return (1);
		}
	}
	return (0);
}
