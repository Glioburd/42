/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:58:32 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/10 16:29:57 by gsauvair         ###   ########.fr       */
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
		if (s[i] == (char) c)
		{
			return (dst + i + 1);
		}
		i++;
	
	}
	return (NULL);
}

/*void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*s1c;
	char	*s2c;

	if (!s1 || !s2 || !n)
		return (NULL);
	i = 0;
	s1c = (char *) s1;
	s2c = (char *) s2;
	while (i < n)
	{
		s1c[i] = s2c[i];
		if (s2c[i] == (unsigned char) c)
			return (s1 + i + 1);
		++i;
	}
	return (NULL);
}*/