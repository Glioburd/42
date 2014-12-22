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

void	draw(t_env *e, t_stock *lst)
{
	int dx;
	int	dy;
	int x_y;

	while(lst->next)
	{
		dx = (lst->next->x - lst->x);
		dy = (lst->next->y - lst->y);
		x_y = (int)(dy * (dx / (lst->next->x - lst->x)));
		if (lst->nl != '\n')
		{	
			if (lst->z >= 1)
			{
				while (dx >= 0)
				{
					mlx_pixel_put(e->mlx, e->win, lst->x + dx, lst->y + x_y, 0x6666FF);
					dx--;
				}
			}
			else
			{
				while (dx >= 0)
				{
					mlx_pixel_put(e->mlx, e->win, lst->x + dx, lst->y + x_y, 0xFF0000);
					dx--;
				}
			}
		}
		lst = lst->next;
	}
}

int		expose_hook(t_env *e)
{
	t_stock	*lst;

	lst = open_f(e);
	draw(e, lst);
	return (0);
}

int		key_hook(int key_code)
{
	if (key_code == 65307)
		exit(0);
	return (0);
}