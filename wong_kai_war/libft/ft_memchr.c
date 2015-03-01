/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:30:46 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/02 22:06:38 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = (unsigned char *)s;
	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (ps[i] != (unsigned char)c)
			{
				i++;
			}
			else
			{
				return ((void *)&ps[i]);
			}
		}
	}
	return (NULL);
}
