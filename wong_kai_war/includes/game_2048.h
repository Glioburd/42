/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:18:48 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 20:47:30 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <ncurses.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <unistd.h>
# include "../libft/libft.h"

# define ESCAPE_KEY 27
# define R_KEY 114
# define C_KEY 99
# define CASE_VALUE env->map[i][j].value
# define CASE_MERGED env->map[i][j].merged
# define COORD &(env->map[i][j])
# define POS_Y e->map[i][j].pos_y

typedef	struct	s_map	{
	int			pos_x;
	int			pos_y;
	int			value;
	int			color;
	char		merged;
}				t_map;

typedef enum	e_enum	{
	WIN_VALUE = 2048
}				t_enum;

typedef	struct	s_env	{
	int			height;
	int			width;
	t_enum		*constantes;
	t_map		**map;
	int			h_quarter;
	int			w_quarter;
	int			win;
}				t_env;

int				movevalue(t_env *env, int key);
void			perma_update(t_env *env);
void			drawmap(t_env *e);
void			move_checker(t_map *a, t_map *b, int *has_moved, t_env *e);
void			game_hook(t_env *env, int key);
int				defeat_check(t_env *env);
void			checkwin(t_env *env);
void			draw_norm_joke(t_env *e, int i, int j);
void			drawvalue(t_env *e, t_map *map);
void			color_tile(t_env *e, t_map *map);
int				addcolor(int value);
void			setcolor(void);
#endif
