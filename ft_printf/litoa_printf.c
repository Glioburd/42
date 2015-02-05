/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   litoa_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 17:55:05 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/04 17:19:19 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	continue_litoa(long int n, char *str, long int b, char *base)
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

char	*litoa(char *base, long int n)
{
	long int	i;
	long int	b;
	long int	save;
	char		*str;

	i = 0;
	save = n;
	save = save < 0 ? save : save * -1;
	b = (long int)ft_strlen(base);
	while (save >= b)
	{
		save /= b;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		exit(-1);
	continue_litoa(n, str, b, base);
	return (str);
}
