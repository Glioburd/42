/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:21:56 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/05 20:37:22 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char 	*ps2;

	i = 0;
	while (n--)
	{
		ps1 = (unsigned char *)s1;
		ps2 = (unsigned char*)s2;
		if (*ps1 != *ps2)
		{
			return(*ps1 - *ps2);
		}
		s1++;
		s2++;
	}
	return(0);
}