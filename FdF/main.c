/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:13:54 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/10 20:45:00 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_pixel_put(t_env *e, int x, int y)
{
	mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), e->color);
	return (0);
}

void	ft_pixel_start(t_env *e)
{
	int		map[2];

	map[0] = 0;
	while (map[0] != e->length)
	{
		map[1] = 0;
		while (map[1] != e->width)
		{
			ft_pixel_put(e, e->tab[map[0]][map[1]][0],
				e->tab[map[0]][map[1]][1]);
			map[1]++;
		}
		map[0]++;
	}
}

/*
** Initialisation des fonctions MLX et des coordonnees de depart.
*/

void	mi(int **tab, int length, int width, char *argvcolor)
{
	t_env	e;

	e.color = WHITE;
	if (argvcolor != NULL)
		ft_arg_color(argvcolor, &e);
	e.move_x = 0;
	e.move_y = 0;
	e.zoom = 0;
	e.t_tab = tab;
	e.length = length;
	e.width = width;
	e.tab = ft_ini_coord(e.t_tab, e.length, e.width, &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "Based window");
	mlx_key_hook(e.win, &ft_keyhook3, &e);
	mlx_expose_hook(e.win, &ft_expose_hook, &e);
	mlx_mouse_hook(e.win, &ft_mousehook, &e);
	mlx_loop(e.mlx);
}

/*
** Check de la tabidite des args.
** Ouverture de la map avec open_file
*/

int		ft_tabid_args(int argc, char **argv, char **str)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		return (-1);
	}
	if (ft_open(fd, str) == -1)
	{
		perror(argv[1]);
		return (-1);
	}
	return (1);
}

/*
** Check des args.
** Creation d'un tableau de int a partir de la map avec ft_tab.
*/

int		main(int argc, char **argv)
{
	t_env	e;
	char	*str;
	int		**tab;
	int		length;
	int		width;

	if (argc > 1 && argc < 4 && ft_tabid_args(argc, argv, &str) == 1)
	{
		if (argc == 3 && ft_valid_arg2(argv[2]) == 0)
			ft_arg2_error(argv[2]);
		else if (argc == 3)
			e.argcolor = argv[2];
		tab = ft_tab(&str, &length, &width);
		if (tab == NULL)
		{
			ft_putstr(argv[1]);
			ft_putendl(" is a corrupted or incorrect map.");
			return (0);
		}
		mi(tab, length, width, argv[2]);
	}
	else
		ft_putstr("You must construct additional pylons : ./fdf map.fdf\n");
	return (0);
}
