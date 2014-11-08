/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:03:19 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/05 13:08:12 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char *pstr;
	const char *pto_find;

	if (to_find == NULL)
		return ((char *)str);
	while (*str != '\0')
	{
		pstr = str;
		pto_find = to_find;
		while (*pstr == *pto_find && *pstr != '\0' && *pto_find != '\0')
		{
			pstr++;
			pto_find++;
		}
		if (*pto_find == '\0')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
