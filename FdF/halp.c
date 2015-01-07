/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 20:12:02 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/07 17:10:17 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	void	ft_write_op(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 35, 35, 0xAFAFAF, "Quit : ESC");
	mlx_string_put(e->mlx, e->win, 35, 55, 0xAFAFAF, "Move : Arrows");
	mlx_string_put(e->mlx, e->win, 35, 75, 0xAFAFAF, "Zoom : +/-");
}

/*void	ft_put_help(t_env *e, int hx, int hy)
{
	int		tmp_x;
	int		tmp_y;
	int		x;
	int		y;

	x = e->sqr_x;
	y = e->sqr_y;
	tmp_x = e->sqr_x;
	tmp_y = e->sqr_y;
	while (x != hx)
	{
		ft_pixel_put(e, (x++ - e->move_x), (y - e->move_y));
	}
	while (y != hy)
	{
		ft_pixel_put(e, (x - e->move_x), (y++ - e->move_y));
	}
	while (x != tmp_x)
	{
		ft_pixel_put(e, (x-- - e->move_x), (y - e->move_y));
	}
	while (y != tmp_y)
	{
		ft_pixel_put(e, (x - e->move_x), (y-- - e->move_y));
	}
}*/
