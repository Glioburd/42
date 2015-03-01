/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:13:35 by gsauvair          #+#    #+#             */
/*   Updated: 2015/03/01 18:43:16 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(length + 1);
	i = 0;
	while (i < length)
	{
		if (s1 && *s1)
		{
			str[i] = *s1;
			s1++;
		}
		else if (s2 && *s2)
		{
			str[i] = *s2;
			s2++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
