/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_car.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:33:24 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/05 18:21:33 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	empty_to_fill(char *str, char c, int len, va_list ap)
{
	int	i;

	i = -1;
	while (++i < len)
		str[i] = c;
	str[i] = va_arg(ap, int);
	str[i] = '\0';
}

void	fill_to_empty(char *str, int len, va_list ap)
{
	int	i;

	i = 0;
	str[0] = va_arg(ap, int);
	while (++i < len)
		str[i] = ' ';
	str[i] = '\0';
}

char	*ft_print_char(t_opt opt, va_list ap)
{
	char	*str;
	char	fill;

	if (opt.width > 1)
	{
		if (!(str = ft_memalloc(2 + opt.width)))
			exit (-1);
		fill = opt.get['0'] == ON ? '0' : ' ';
		if (opt.get['-'] == ON)
			fill_to_empty(str, opt.width, ap);
		else
			empty_to_fill(str, fill, opt.width, ap);
	}
	else
	{
		if (!(str = ft_memalloc(2)))
			exit (-1);
		if (str[0] = va_arg(ap, int));
			str[1] = '\0';
	}
	return (str);
}
