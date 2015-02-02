/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 18:43:26 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/31 17:54:23 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	continue_itoa(int n, char *str, int b, char *base)
{
	char	buf[2];

	if (n < 0)
	{
		n = -n;
		str = ft_strcat(str, "-");
	}
	if (n < b)
	{
		buf[0] = base[n];
		buf[1] = '\0';
		str = ft_strcat(str, buf);
	}
	else
	{
		continue_itoa(n / b, str, b, base);
		continue_itoa(n % b, str, b, base);
	}
}

char	*itoa(char *base, int n)
{
	int		i;
	int		b;
	int		save;
	char	*str;

	i = 0;
	save = n;
	save = save < 0 ? save : save * -1;
	b = (int)ft_strlen(base);
	while (save >= b)
	{
		save /= b;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		exit(-1);
	continue_itoa(n, str, b, base);
	return (str);
}
