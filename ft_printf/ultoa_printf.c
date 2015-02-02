/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultoa_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 18:06:17 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/31 18:21:37 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

"ft_printf.h"

void	cont_ult(unsigned long int n, char *s, unsigned long b, char *d)
{
	char	buf[2];

	if (n < b)
	{
		buf[0] = d[n];
		buf[1] = '\0';
		s = ft_strcat(s, buf);
	}
	else
	{
		cont_ult(n / b, s, b, d);
		cont_ult(n % b, s, b, d);
	}
}

char	*ultoa(char *base, unsigned long n)
{
	unsigned long		i;
	unsigned long		b;
	unsigned long		save;
	char				*str;

	i = 0;
	save = n;
	b = (unsigned long)ft_strlen(base);
	while (save >= b)
	{
		save /= b;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		exit(-1);
	cont_ult(n, str, b, base);
	return (str);
}
