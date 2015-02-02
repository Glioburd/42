/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 17:19:58 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/02 15:23:00 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base(int flag)
{
	char	*base;

	if (flag == 4)
		base = ft_strdup("01234567");
	else if (flag == 6 || flag == 8)
		base = ft_strdup("0123456789abcdef");
	else if (flag == 7)
		base = ft_strdup("0123456789ABCDEF");
	else if (flag == 9)
		base = ft_strdup("01");
	else
		base = ft_strdup("0123456789");
	if (base == NULL)
		exit(-1);
	return (base);
}

char	*ul(int flag, char *base, va_list ap)
{
	char	*str;

	if (flag == 5)
		str = ft_ultoa(base, va_arg(ap, unsigned long));
	else
		str = ft_ltoa(base, va_arg(ap, long int));
	return (str);
}

char	*ft_print_number(t_opt opt, va_list ap, int flag)
{
	char	*str;
	char	*base;
	int		n;

	base = ft_base(flag);
	if (opt.get['l'] == ON)
		str = ul(flag, base, ap);
	else
	{
		if (flag == 4 || (flag >= 6 && flag <= 8))
			if (flag == 8)
				str = ft_strjoin("0x", ft_ultoa(base, va_arg(ap, long)));
			else
			{
				n = va_arg(ap, int);
				str = ft_uitoa(base, n);
			}
		else if (flag == 5)
			str = uitoa(base, va_arg(arg, unsigned int));
		else
			str = itoa(base, va_arg(arg, int));
	}
	return (final_print(str, opt));
}
