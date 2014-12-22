/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:13:54 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/16 16:34:03 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Initialisation des fonctions MLX et des coordonnees de depart.
*/

void	ft_mlx_init(int **tab, int lenght, int width)
{
	t_env	e;

	e.movex = 0;
	e.movey = 0;
	e.zoom = 0;
	e.tab = tab;
	e.lenght = lenght;
	e.width = width;
	/*e.tab = ft_init_coord(e.tab, e.lenght, e.width, &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "Based window");
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);*/
}

/*
** Check de la validite des args.
** Ouverture de la map avec open_file
*/

int		ft_valid_args(int argc, char **argv, char **str)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		return (-1);
	}
//	if (get_next_line(fd, str) == -1)
	if (ft_open_file(fd, str) == -1)
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
	int		lenght;
	int		width;

	if (argc >= 2 && ft_valid_args(argc, argv, &str) == 1)
	{
		tab = ft_tab(&str, &lenght, &width);
		if (tab == NULL)
		{
			ft_putstr(argv[1]);
			ft_putendl("The map is corrupted or incorrect.");
			return (0);
		}
		ft_mlx_init(tab, lenght, width);			
	}
	else
		ft_putstr("You must execute FdF with a map : ./fdf map.fdf\n");
	return (0);
}
