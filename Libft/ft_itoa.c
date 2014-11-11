/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:30:02 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 14:40:39 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** On compte le nombre de chiffres que contient n
** pour creer un buffer adapte dans itoa
*/
static int		count_digit(int n)
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
/*
** J'ai extremement honte de l'exception en dur pour le cas -2147483648.
** Pardon.
*/
char	*ft_itoa(int n)
{
	char	*buf;
	int		j;

	if (n == -2147483648)
		return("-2147483648");
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
