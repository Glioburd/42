/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:38:36 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/16 12:32:26 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_coord(int **tab, int lenght, int width, t_env e)
{
	int		***coord;
	int		ind[3];

	ind[2] = e->zoom;
	if (!(coord = (int***)malloc(sizeof(coord) * (length + 1))))
		return (NULL);
	ind[0] = 0;
	ft_verif_value(tab, length, width);
	while (ind[0] < length)
	{
		if (!(coord[ind[0]] = malloc(sizeof(*coord) * (width + 1))))
			return (NULL);
		ind[1] = 0;
		while (ind[1] != width)
		{
			if (!(coord[ind[0]][ind[1]] = malloc(sizeof(coord) * 2)))
				return (NULL);
			ft_init_c(&coord[ind[0]][ind[1]][0],
					&coord[ind[0]][ind[1]][1], ind, tab);
			ind[1]++;
		}
		ind[0]++;
	}
	return (coord);
}