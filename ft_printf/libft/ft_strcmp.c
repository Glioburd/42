/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:42:27 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 18:15:29 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (!p1 && !p2)
		return (0);
	i = 0;
	while (p1[i])
	{
		if (!p2[i] || p2[i] != p1[i])
			return (p1[i] - p2[i]);
		i++;
	}
	if (p1[i] != p2[i])
		return (p1[i] - p2[i]);
	return (0);
}
