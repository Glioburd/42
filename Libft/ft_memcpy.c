/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:44:18 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/09 23:48:21 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;
	if (!dest || !src || !n)
		return (dest);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i > n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
