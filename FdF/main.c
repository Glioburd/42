/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 15:25:36 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/29 17:15:07 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
static int		ft_expose_hook(t_env *e)
{
	int	fd;

	fd = open(e->argv, O_RDONLY);
	if (fd == -1)
	{
		perror(e->argv);
		exit(-1);
	}
	ft_read(fd, e);
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
	if (argc > 1)
	{
		t_env	e;
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 420, 420, "Based window");
		mlx_expose_hook(e.win, ft_expose_hook, &e);
		mlx_key_hook(e.win, ft_key_hook, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		ft_putstr("How can I generate a graphic thing without a map ? HOW ?");
		ft_putstr(" CAN YOU TELL ME ?\n");
		ft_putstr("Use ./fdf [map]\n");
	}
	return (0);
}
