/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:30:02 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/10 16:10:55 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** On compte le nombre de chiffres que contient n
** pour creer un buffer adapte dans itoa
*/
long int		count_digit(long int n)
{
	int	count;

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

char	*ft_itoa(long int n)
{
	char		*buf;
	long int	j;

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
