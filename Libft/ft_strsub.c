/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:28:38 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/11 18:30:43 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
	{
		return (0);
	}
	ret = ft_strnew(len);
	if (ret)
	{
		ret = ft_strncpy(ret, (s + start), len);
	}
	return (ret);
}
