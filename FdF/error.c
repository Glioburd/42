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

/*static int		ft_is_arg_valid(char *)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) >= 0 && ft_strlen(filename) > 4)
	{
		if (!ft_strcmp(".fdf" || ".txt", ft_strsub(filename, ft_strlen(filename) - 4, 4)))
		{
			close(fd);
			return (1);
		}
		else
		{
			close(fd);
			return (0);
		}
	}
	return (0);
}
*/