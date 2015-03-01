/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:12:12 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 19:20:29 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

/*
** getmaxyx : collect max size of the window
** WINDOW *field : initial window
** draw_borders : draw borders
** wrefresh : refresh all every window
** delwin : clean
** ---
** Source : http://shar.as/fa6DB
*/

static void		alloc_map(t_env *env)
{
	int		i;

	if ((env->map = malloc(sizeof(t_map *) * 4)) == NULL)
		return ;
	i = 0;
	while (i < 4)
	{
		if ((env->map[i] = malloc(sizeof(t_map) * 4)) == NULL)
			return ;
		ft_bzero(env->map[i], sizeof(t_map) * 4);
		i++;
	}
}

static void		initvalue(t_env *env)
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

static void		init_env(t_env *env)
{
	initscr();
	curs_set(0);
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	alloc_map(env);
	initvalue(env);
}

static int		is_win_value_correct(int nb)
{
	int			i;

	i = 2;
	while (i != nb)
	{
		if (i > 256000)
			return (1);
		i += i;
	}
	return (0);
}

int				main(void)
{
	t_env	env;
	t_enum	constantes;
	int		key;
	int		carre;

	carre = is_win_value_correct(WIN_VALUE);
	if (carre == 1 || WIN_VALUE < 2 || !WIN_VALUE)
	{
		ft_putnbr(WIN_VALUE);
		ft_putendl(" is a wrong value.");
		ft_putendl("Please put a power of two, like 2, 4, 8, 16...");
		exit(0);
	}
	env.constantes = &constantes;
	init_env(&env);
	getmaxyx(stdscr, env.height, env.width);
	mvwprintw(stdscr, env.height / 2, env.width / 2 - 16, "WONG KAI WAR");
	while ((key = getch()) != 27)
	{
		game_hook(&env, key);
		perma_update(&env);
	}
	endwin();
	curs_set(1);
	return (0);
}
