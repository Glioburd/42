/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 11:21:05 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 19:15:09 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

static void	gen_new_map(t_env *env)
{
	int	i;
	int	j;

	srand(time(0));
	i = rand() % 4;
	j = rand() % 4;
	CASE_VALUE = 2;
	while (CASE_VALUE != 0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	CASE_VALUE = (rand() % 10 == 0) ? 4 : 2;
}

static void	resetvalue(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			CASE_VALUE = 0;
			j++;
		}
		i++;
	}
	gen_new_map(env);
}

static void	reset_merge(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			CASE_MERGED = 0;
			j++;
		}
		i++;
	}
}

static void	add_newvalue(t_env *env)
{
	int	i;
	int	j;
	int	check;

	srand(time(0));
	i = rand() % 4;
	j = rand() % 4;
	while (CASE_VALUE != 0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	check = rand() % 10;
	if (check == 9)
		CASE_VALUE = 4;
	else
		CASE_VALUE = 2;
}

/*
**  Actions done by user
*/
void		game_hook(t_env *env, int key)
{
	int	nomove;
	int	test;

	if (key == R_KEY)
		resetvalue(env);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP ||
		key == KEY_DOWN)
	{
		reset_merge(env);
		nomove = movevalue(env, key);
		if (env->win == 1)
			checkwin(env);
		if (nomove > 0)
			add_newvalue(env);
		else
		{
			test = defeat_check(env);
			if (test == 1)
				resetvalue(env);
		}
	}
}
