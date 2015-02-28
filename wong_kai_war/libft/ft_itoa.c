/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:30:02 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/27 16:37:12 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** On compte le nombre de chiffres que contient n
** pour creer un buffer adapte dans itoa
*/
static int	count_digit(int n)
{
	int		count;

	count = 0;
	if (n <= 0)
	{
		count = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*buf;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	buf = ft_strnew(count_digit(n));
	j = count_digit(n) - 1;
	if (buf)
	{
		if (n < 0)
		{
			buf[0] = '-';
			n = -n;
		}
		if (n == 0)
			*buf = '0';
		while (n > 0)
		{
			buf[j] = '0' + (n % 10);
			n /= 10;
			j--;
		}
	}
	return (buf);
}
