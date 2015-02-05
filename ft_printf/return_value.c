/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 19:17:29 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/05 18:21:14 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab			g_tab[10] =
{
	{"c", ft_print_char},
	{"s", ft_print_str},
	{"d", ft_print_number},
	{"i", ft_print_number},
	{"o", ft_print_number},
	{"u", ft_print_number},
	{"x", ft_print_number},
	{"X", ft_print_number},
	{"p", ft_print_number},
	{"b", ft_print_number}
};

int		ft_flag(t_opt opt, char **str, va_list ap)
{
	int		i;
	int		flag;
	int		len;
	char	*tmp;
	char	*str2;

	i = -1;
	flag = 0;
	while (i < 10)
	{
		++i;
		if (**str == g_tab[i].flag[0])
		{
			tmp = g_tab[i].func(opt, ap, i);
			flag++;
		}
	}
	if (flag)
	{
		(*str)++;
		str2 = ft_strjoin(tmp, *str)
		*str = str2;
	}
	len = ft_strlen(*str);
	return (len);
}

int		ft_display(va_list ap, char **str)
{
	int		flag;
	t_opt	opt;
	opt = get_opt(str, ap);
	flag = ft_flag(opt, str, ap);
	return (flag);
}
