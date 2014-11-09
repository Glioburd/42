/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:54:37 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/08 22:54:40 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	ret;

	ret = ft_strcmp(s1, s2);
	if (s1[0] != s2[0])
		return (0);
	if (ret != 0)
		return (0);
	else
		return (1);
}
