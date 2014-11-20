/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:40:49 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 18:14:31 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
	char	*ps1;
	size_t	i;

	ps1 = dest;
	i = 0;
	if (!src)
		return ((char *)src);
	while (*dest)
		dest++;
	while (src[i] != '\0')
		*dest++ = src[i++];
	*dest = '\0';
	return (ps1);
}
