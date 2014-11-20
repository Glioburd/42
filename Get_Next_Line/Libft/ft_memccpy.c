/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:58:32 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 18:13:50 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*d;
	const char			*s;
	size_t				i;

	if (!dst || !src || !n)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (i < n && s[i - 1] != c)
	{
		d[i] = s[i];
		if (s[i] == (char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
