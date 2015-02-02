/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:46:51 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/26 17:15:00 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_ap(va_list ap)
{
	va_list	ap2;
	char	*ptr_value;
	int		return_value;

	return_value = ON;
	va_copy(ap2, ap);
	ptr_value = va_arg(ap2, char*);
	if (!(ptr_value))
		return_value = OFF;
	else if (!(*ptr_value))
		return_value = 0;
	va_end(ap2);
	return (return_value);
}

char	*fill(char c, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_memalloc(len + 1)))
		exit(-1);
	while (i < len)
	{
		str[i] = c
		i++;
	}
	str[i] = '\0'
	return(str);
}

char	*continue_print(char *str, t_opt opt)
{
	char	c;

	if (opt.width > 1 && (unsigned int)opt.width > ft_strlen(str))
	{
		c = opt.get['0'] == ON ? '0' : ' ';
		if (opt.get['-'] == ON)
			str = ft_strjoin(str, fill(' ', opt.width - (int)ft_strlen(str)));
		else
			str = ft_strjoin(fill(c, opt.width - (int)ft_strlen(str)), str)
		if (str == NULL)
			exit(-1);
	}
	return (str);
}

char	*ft_print_str(t_opt opt, va_list ap, int check)
{
	char	*str;

	check = ft_check_ap(ap)
	if (check == 0)
		return (NULL);
	if (opt.get['l'] == ON)
		exit (-1);
	if (opt.get['-'] == ON && opt.len_prev < 1)
	{
		if (!(str = ft_memalloc(1)))
			exit (-1);
		*str = '\0';
	}
	else if (opt.get['.'] == ON && opt.len_prev > 0)
	{
		str = check == OFF ? ft_strdup("(null)") : ft_strdup(va_arg(ap, char *));
		if ((unsigned int)opt.len_prev < ft_strlen(str))
			str = ft_strsub(str, 0 , (size_t)opt.len_prev);
	}
	else
		str = check == OFF ? ft_strdup("(null)") : ft_strdup(va_arg(ap, char *));
	return (continue_print);
}