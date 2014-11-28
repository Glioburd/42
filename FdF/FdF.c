/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvai@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:25:07 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/26 17:57:54 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_draw(void *mlx, void *win)
{
	int	x;
	int	y;

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
}

int		ft_expose_hook(t_env *e)
{
	ft_draw(e->mlx, e->win);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	printf("%d (%d:%d)\n", button, x, y);
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc >= 1)
	{
		t_env	e;
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 420, 420, "Based window");
		mlx_expose_hook(e.win, ft_expose_hook, &e);
		mlx_key_hook(e.win, ft_key_hook, &e);
		mlx_mouse_hook(e.win, ft_mouse_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		return (-1); //error
	return (0);
}
