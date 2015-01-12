/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 18:34:16 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/12 19:33:22 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_x(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->length)
	{
		j = 0;
		while (j < e->width - 1)
		{
			ft_draw_x(e, i, j);
			j++;
		}
		i++;
	}
}

void	ft_init_y(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->length - 1)
	{
		j = 0;
		while (j < e->width)
		{
			ft_draw_y(e, i, j);
			j++;
		}
		i++;
	}
}

void	ft_coord(int *x, int *start, int alpha, int beta)
{
	if (alpha < beta)
	{
		*x = alpha;
		*start = beta;
	}
	else
	{
		*x = beta;
		*start = alpha;
	}
}

void	ft_draw_y(t_env *e, int i, int j)
{
	float	m;
	float	p;
	int		start;
	int		y;
	int		x;

	y = e->tab[i + 1][j][1] - e->tab[i][j][1];
	x = e->tab[i + 1][j][0] - e->tab[i][j][0];
	m = (float)y / (float)x;
	p = e->tab[i][j][1] - (m * e->tab[i][j][0]);
	ft_coord(&x, &start, e->tab[i][j][0], e->tab[i + 1][j][0]);
	while (x < start)
	{
		y = (int)((m * x + p) + 0.5);
		ft_pixel_put(e, x, y);
		x++;
	}
	ft_coord(&y, &start, e->tab[i][j][1], e->tab[i + 1][j][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		ft_pixel_put(e, x, y);
		y++;
	}
}

void	ft_draw_x(t_env *e, int i, int j)
{
	float	m;
	float	p;
	int		start;
	int		y;
	int		x;

	y = e->tab[i][j + 1][1] - e->tab[i][j][1];
	x = e->tab[i][j + 1][0] - e->tab[i][j][0];
	m = (float)y / (float)x;
	p = e->tab[i][j][1] - (m * e->tab[i][j][0]);
	ft_coord(&x, &start, e->tab[i][j][0], e->tab[i][j + 1][0]);
	while (x < start)
	{
		y = (int)((m * x + p) + 0.5);
		ft_pixel_put(e, x, y);
		x++;
	}
	ft_coord(&y, &start, e->tab[i][j][1], e->tab[i][j + 1][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		ft_pixel_put(e, x, y);
		y++;
	}
}
