/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:43:13 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/07 15:30:59 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (ft_strnew(ft_strlen(s)));
	if (ret)
	{
		while (s[i] != '\0')
		{
			ret[i] = (*f)(s[i]);
			i++;
		}
	}
	return (ret);
}
