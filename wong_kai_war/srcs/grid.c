/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:19:49 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/28 17:38:40 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_2048.h"

void	init_grid(t_env *env)
{
	int	i;

	env ->play.map = MAL(int*);
	i = 0;
	while (i++ < 4)
		env->play.map[i] = ft_memalloc(S(int, 4));
}

void	init_play(t_env *env)
{
	init_grid(env);
	env->play.map = map;
	start_kaiwar(env);
	return ;
}