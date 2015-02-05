/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 15:48:37 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/05 16:31:39 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_turn_off(void)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_memalloc(127)))
		exit(-1);
	while (i < 127)
	{
		str[i] = OFF;
		i++;
	}
	return (str);
}

int		get_info(char **str, va_list ap)
{
	int		val;

	val = 0;
	(*str)++;
	if (ft_isdigit(**str))
	{
		val = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
		(*str)--;
	}
	else if (**str == '*')
		val = va_arg(ap, int);
	if (val < 0)
		val *= -1;
	return (val);
}

int		ft_is_option(char c)
{
	if (ft_strchr(OPTION, c))
		return (1);
	if (c == '.')
		return (2);
	if (ft_isdigit(c))
		return (3);
	return (0);
}

void	ft_check_option(char *get, char **str, t_opt *opt, va_list ap)
{
	int	i;

	if (ft_isdigit(**str) && (**str != '0' || **str == '*'))
	{
		if (**str == '*')
			opt->width = va_arg(ap, int);
		else
		{
			opt->width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
			(*str)--;
		}
	}
	else if (ft_is_option(**str) == 2)
	{
		get['.'] = ON;
		opt->len_prev = get_info(str, ap);
	}
	else if (ft_is_option(**str) == 3)
	{
		i = (unsigned int)(unsigned char)**str;
		get[i] = ON;
	}
}

t_opt	ft_get_option(char **str, va_list ap)
{
	t_opt	tmp;

	if (!(tmp.get = ft_memalloc(127)))
		exit (-1);
	tmp.get = ft_turn_off();
	tmp.width = 0;
	tmp.len_prev = -1;
	while (*str && ft_is_option(**str))
	{
		ft_check_option(tmp.get, str, &tmp, ap);
		(*str)++;
	} 
	if (tmp.width < 0)
		tmp.width = tmp.width * -1;
	return (tmp);
}
