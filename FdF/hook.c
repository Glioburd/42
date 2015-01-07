/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 15:52:42 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/07 19:44:56 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_write_op(t_env *e);

static void	ft_keyhook(int key, t_env *e)
{
	if (key == 65453)
	{
		e->zoom -= 2;
		if (e->zoom == -32)
		{
			e->zoom = -30;
		}
		mlx_clear_window(e->mlx, e->win);
		e->tab = ft_init_coord(e->t_tab, e->length, e->width, e);
		ft_expose_hook(e);	
	}
}

int			ft_expose_hook(t_env *e)
{

	ft_pixel_start(e);
	ft_init_x(e);
	ft_init_y(e);
	ft_write_op(e);
	return (0);
}

/*
** Fleche du haut
** Touche +
*/
int		ft_keyhook2(int key, t_env *e)
{
	if (key == 65362)
		e->move_y -= 15;
	if (key == 65451)
	{
		e->zoom += 2;
		if (e->zoom == 100)
			e->zoom = 98;
		/*e->move_x_z += 15;
		e->move_y_z += 15;*/
		e->tab = ft_init_coord(e->t_tab, e->length, e->width, e);
	}
	if (key == 65365)
		e->high += 0.10;
		printf("%d\n", key);
	mlx_clear_window(e->mlx, e->win);
	ft_expose_hook(e);
	ft_keyhook(key, e);
	return (0);
}

int		ft_keyhook3(int key, t_env *e)
{
	if (key == 65307)
		exit(0);
	if (key == 65363)
		e->move_x += 15;
	if (key == 65361)
		e->move_x -= 15;
	if (key == 65364)
		e->move_y += 15;
	mlx_clear_window(e->mlx, e->win);
	ft_expose_hook(e);
	ft_keyhook2(key, e);
	return (0);
}

int		ft_mousehook(int mouse, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (mouse == 1)
	{
		e->zoom += 2;
		if (e->zoom == 100)
			e->zoom = 96;
		e->move_x_z += 15;
		e->move_y_z += 15;
		mlx_clear_window(e->mlx, e->win);
		e->tab = ft_init_coord(e->t_tab, e->length, e->width, e);
		ft_expose_hook(e);
	}
	if (mouse == 3)
	{
		e->zoom -= 2;
		if (e->zoom == -32)
			e->zoom = -30;
		mlx_clear_window(e->mlx, e->win);
		e->tab = ft_init_coord(e->t_tab, e->length, e->width, e);
		ft_expose_hook(e);
	}
	return (0);
}