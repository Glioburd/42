/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:12:09 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/05 16:12:13 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(const char *str)
{
	ft_putstr("fdf: ");
	if (!str)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
	}
	else
		perror(str);
	exit (0);
}
