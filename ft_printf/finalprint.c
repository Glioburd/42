/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:34:06 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/05 16:41:51 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_details(char *str, t_opt opt)
{
	int		val;

	val = 0;
	if ((opt.get['+'] == ON && *str != '-') || (opt.width == 0 && opt.get[' '] == ON && *str != '-'))
		val++;
	if (opt.len_prev > ((int)ft_strlen(str) + val))
		return (str);
	else
		str = ft_strsub(str, 0, (size_t)opt.len_prev);
	return (str);
}

char	*final_print(char *str, t_opt opt)
{
	char	c;

	if (opt.width > 1 && opt.width > (int)ft_strlen(str))
	{
		c = (opt.get['0'] == ON ? '0' : ' ');
		if (opt.get['-'] == ON)
		{
			str = ft_strjoin(str, fill(' ', opt.width - (int)ft_strlen(str)));
		}
		else
		{
			str = ft_strjoin(fill(c, opt.width - (int)ft_strlen(str)), str);
		}
	}
	return (str);
}

char	*nextprint(char *str, t_opt opt)
{
	if (opt.get['.'] == ON)
		str = print_details(str, opt);
	if (opt.get['+'] == ON && *str != '-')
		str = ft_strjoin("+", str);
	else if (opt.width == 0 && opt.get[' '] == ON && *str != '-')
		str = ft_strjoin(" ", str);
	return (final_print(str, opt));
}