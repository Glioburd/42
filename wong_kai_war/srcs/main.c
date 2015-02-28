/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:12:12 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/28 17:42:22 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>



/*
** getmaxyx : collect max size of the window
** WINDOW *field : initial window
** draw_borders : draw borders
** wrefresh : refresh all every window
** delwin : clean
**
** Source : http://shar.as/fa6DB
*/

int main(void)
{
	t_env	env;

	init_play(&env);
	initscr();
	noecho();
	ft_draw_grid();
	return (0);
}