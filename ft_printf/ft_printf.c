/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 16:51:21 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/02 14:58:56 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find(const char *str)
{
	int		i;

	i = -1;
	while (str[i])
	{
		++i;
		if (str[i] == '%' && str[i + 1] == '%')
			return (i);
	}
	return (-1);
}

int		ft_putpercent(const char *str)
{
	int		i;
	int		find;

	i = -1;
	find = ft_find(str);
	while (str[i])
	{
		++i;
		if (i != find)
		{
			write(1, &str[i], 1);
		}
	}
	return (i - 1);
}

int		ft_putstd(const char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

/*
** Check the first flag, print the arg if no flags has been found.
*/

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		flag;
	int		size;
	char	**split;

	i = -1;
	size = 0;
	va_start(ap, str);
	if (!(ft_strchr(str, '%')))
		return (ft_putstd(str));
	flag = (str[0] == '%') ? 1 : 0;
	if (ft_find(str) != -1)
		return (ft_putpercent(str));
	if (!(split = ft_strsplit(str, '%')))
		return (size);
	while (split[++i])
	{
		if (i != 0 || flag)
			ft_display(ap, &split[i]);
		ft_putstr(split[i]);
		size = size + ft_strlen(split[i]);
	}
	va_end(ap);
	return (size);
}
