/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:12:06 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/05 19:19:25 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*pstr;
	const char	*pto_find;
	size_t		i;

	i = 0;
	if (to_find == NULL)
		return ((char *)str);
	while (*str != '\0' && i != len)
	{
		pstr = str;
		pto_find = to_find;
		while (*pstr == *pto_find && *pstr != '\0' && *pto_find != '\0')
		{
			pstr++;
			pto_find++;
		}
		i++;
		if (*pto_find == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
