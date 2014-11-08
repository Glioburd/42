/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:13:35 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/07 21:30:35 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ret)
	{
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
	}
	return (ret);
}
