/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:38:56 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/26 18:41:27 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "FdF.h"
//#include "get_next_line.h"
//#include "./Libft/libft.h"

typedef	struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_env
{
	void *mlx;
	void *win;
	int	height;
	int	width;
}		t_env;

#endif