/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:12:29 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/05 16:12:31 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*draw(void *mlx, void *win)
{
	int		x;
	int		y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		key_hook(int key_code)
{
	ft_putnbr(key_code);
	ft_putchar('\n');
	if (key_code == 53)
		exit(0);
	return (0);
}

void	init(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "fdf");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
