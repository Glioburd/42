/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 21:32:37 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 18:32:55 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblanc(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;

	if (!s)
	{
		return (0);
	}
	i = 0;
	while (ft_isblanc(s[i]))
	{
		i++;
	}
	len = ft_strlen(s) - 1;
	while (len && ft_isspace(s[len]))
	{
		len--;
	}
	if (len < i)
	{
		return (ft_strdup (""));
	}
	return (ft_strsub(s, i, len - (size_t)i + 1));
}
