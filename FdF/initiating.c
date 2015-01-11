/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:38:36 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/10 20:19:37 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Formule projection isometrique
*/

void	ft_init_c(int *x, int *y, int *map, int **tab)
{
	float	tmp;

	tmp = 15. + (35. + map[2]) * (0.82 * map[0] + 0.60 * map[1]);
	*x = (int)(tmp + 0.5);
	tmp = 0.60 * (0.60 * map[0] - 0.82 * map[1]);
	tmp -= 0.05 * tab[map[0]][map[1]];
	tmp *= (35. + map[2]);
	tmp += 533.;
	*y = (int)(tmp + 0.5);
}

void	ft_max_dim(int **tab, int length, int width)
{
	int		i;
	int		j;

	i = 0;
	while (i != length)
	{
		j = 0;
		while (j != length)
		{
			if ((tab[i][j] > 1000) || (tab[i][j] < -1000))
			{
				ft_putendl("Value too high in the map");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int		***ft_ini_coord(int **tab, int length, int width, t_env *e)
{
	int		***coord;
	int		map[3];

	map[2] = e->zoom;
	if (!(coord = (int***)malloc(sizeof(coord) * (length + 1))))
		return (NULL);
	map[0] = 0;
	ft_max_dim(tab, length, width);
	while (map[0] < length)
	{
		if (!(coord[map[0]] = malloc(sizeof(*coord) * (width + 1))))
			return (NULL);
		map[1] = 0;
		while (map[1] != width)
		{
			if (!(coord[map[0]][map[1]] = malloc(sizeof(coord) * 2)))
				return (NULL);
			ft_init_c(&coord[map[0]][map[1]][0],
				&coord[map[0]][map[1]][1], map, tab);
			map[1]++;
		}
		map[0]++;
	}
	return (coord);
}
