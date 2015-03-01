/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:46:47 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 20:05:43 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (!p1 && !p2)
	{
		return (0);
	}
	i = 0;
	while (p1[i] && i < n)
	{
		if (p2[i] == '\0' || p2[i] != p1[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return (p1[i] - p2[i]);
	}
	return (0);
}
