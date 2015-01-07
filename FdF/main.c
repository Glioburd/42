/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:13:54 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/07 19:45:35 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_pixel_put(t_env *e, int x, int y)
{
	mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), 0xFFFFFF);
	return (0);
}

void		ft_pixel_start(t_env *e)
{
	int		map[2];

	map[0] = 0;
	while (map[0] != e->length)
	{
		map[1] = 0;
		while (map[1] != e->width)
		{
			ft_pixel_put(e, e->tab[map[0]][map[1]][0], e->tab[map[0]][map[1]][1]);
			map[1]++;
		}
		map[0]++;
	}
}

/*
** Initialisation des fonctions MLX et des coordonnees de depart.
*/

void	ft_mlx_init(int **tab, int length, int width)
{
	t_env	e;

	e.high = 0.06;
	e.move_x = 0;
	e.move_y = 0;
	e.zoom = 0;
	e.t_tab = tab;
	e.length = length;
	e.width = width;
	e.tab = ft_init_coord(e.t_tab, e.length, e.width, &e);
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
//	if (get_next_line(fd, str) == -1)
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
	char	*str;
	int		**tab;
	int		length;
	int		width;

	if (argc >= 2 && ft_tabid_args(argc, argv, &str) == 1)
	{
		tab = ft_tab(&str, &length, &width);
		if (tab == NULL)
		{
			ft_putstr(argv[1]);
			ft_putendl("The map is corrupted or incorrect.");
			return (0);
		}
		ft_mlx_init(tab, length, width);			
	}
	else
		ft_putstr("You must construct additional pylons : ./fdf map.fdf\n");
	return (0);
}
