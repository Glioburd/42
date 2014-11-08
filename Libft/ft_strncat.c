/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:42:10 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/06 14:17:49 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		t;

	t = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i + t] = src[i];
		i++;
	}
	dest[i + t] = '\0';
	return (dest);
}
