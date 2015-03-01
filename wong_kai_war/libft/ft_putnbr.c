/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:08:04 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/15 18:56:02 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	int		div;

	div = 1;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
		ft_putchar('-');
	else
		n = -n;
	while (n / div <= -10)
		div *= 10;
	while (div)
	{
		ft_putchar('0' - n / div % 10);
		div /= 10;
	}
}
