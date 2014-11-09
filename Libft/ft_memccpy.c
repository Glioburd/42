/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:58:32 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/09 20:21:43 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*d;
	const char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	while (n > i && s[i - 1] != c)
	{
		d[i] = s[i];
		i++;
		if (i == n)
			return (NULL);
	}
	dest += i;
	return (dest);
}
