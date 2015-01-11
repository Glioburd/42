/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 20:12:02 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/10 20:33:44 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_write_op(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 35, 35, 0x32CD32, "Quit : ESC");
	mlx_string_put(e->mlx, e->win, 35, 55, 0x32CD32, "Move : Arrows");
	mlx_string_put(e->mlx, e->win, 35, 75, 0x32CD32, "Zoom : + / - or M1 / M2");
}

int		ft_valid_arg2(char *av)
{
	if (ft_strcmp(av, "BLUE") == 0 || ft_strcmp(av, "RED") == 0 ||
		ft_strcmp(av, "GREEN") == 0 || (ft_strcmp(av, "YELLOW") == 0) ||
		ft_strcmp(av, "PINK") == 0 || ft_strcmp(av, "TEAL") == 0 ||
		ft_strcmp(av, "ORANGE") == 0 || (ft_strcmp(av, "MATRIX") == 0))
		return (1);
	else
		return (0);
}

void	ft_arg2_error(char *av)
{
	ft_putstr(av);
	ft_putendl(" is an unavailable color. You can run with :");
	ft_putendl("-BLUE");
	ft_putendl("-RED");
	ft_putendl("-GREEN");
	ft_putendl("-YELLOW");
	ft_putendl("-PINK");
	ft_putendl("-TEAL");
	ft_putendl("-ORANGE");
	ft_putendl("-MATRIX");
	ft_putchar('\n');
	ft_putendl("Exemple : ./fdf map.fdf ORANGE");
	exit(0);
}

/*
** Doesn't work with e->color = ft_atoi(argvcolor);
** Need fixes.
*/

int		ft_arg_color(char *argvcolor, t_env *e)
{
	if (ft_strcmp(argvcolor, "BLUE") == 0)
		e->color = BLUE;
	else if (ft_strcmp(argvcolor, "RED") == 0)
		e->color = RED;
	else if (ft_strcmp(argvcolor, "GREEN") == 0)
		e->color = GREEN;
	else if (ft_strcmp(argvcolor, "YELLOW") == 0)
		e->color = YELLOW;
	else if (ft_strcmp(argvcolor, "PINK") == 0)
		e->color = PINK;
	else if (ft_strcmp(argvcolor, "TEAL") == 0)
		e->color = TEAL;
	else if (ft_strcmp(argvcolor, "ORANGE") == 0)
		e->color = ORANGE;
	else if (ft_strcmp(argvcolor, "MATRIX") == 0)
		e->color = MATRIX;
	return (0);
}
