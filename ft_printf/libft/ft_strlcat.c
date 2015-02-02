/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:54:52 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 18:25:31 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	dst_lenght;

	d = dst;
	s = src;
	n = size;
	while (n-- != '\0' && *d != '\0')
		d++;
	dst_lenght = d - dst;
	n = size - dst_lenght;
	if (n == 0)
		return (dst_lenght + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dst_lenght + (s - src));
}
