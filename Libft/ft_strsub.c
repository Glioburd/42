/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:28:38 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/08 22:13:34 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	ret = ft_strnew(len);
	i = start;
	while (i < len + start)
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	return (ret);
}