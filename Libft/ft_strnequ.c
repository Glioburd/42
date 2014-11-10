/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:05:40 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/10 15:35:56 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
/*	int	ret;
	if ((!s1 && s2) || (s1 && !s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	ret = ft_strncmp(s1, s2, n);
	if (ret == 0)
		return (1);
	return (0);*/
	if (s1 && s2)
		return (!ft_strncmp(s1, s2, n));
	return (0);
}
