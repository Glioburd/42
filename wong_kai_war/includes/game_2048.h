/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:18:48 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/28 17:46:59 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "../libft/libft.h"
# define ESCAPE_KEY 27

enum				e_const
{
	WIN_VALUE = 	2048
}					t_const;

typedef struct 		s_play
{
	int				**map;
	int				score;
}					t_play;

typedef struct		s_env
{
	int 			width;
	int 			height;
	t_play			play;
}					t_env;

/*
* Inits functions
*/
void	init_play(t_env *env);

/*
* Draw functions
*/
void	draw_borders(WINDOW *screen);
void	ft_draw_grid(void);
#endif
