/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:10:17 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/05 17:29:51 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char *s;

	d = dst;
	s = src;
	if (d <= s || s >= (d + n))
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dst);
}
