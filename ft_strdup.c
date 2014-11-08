/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:38:16 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/04 14:27:04 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char*)malloc(sizeof(*s2) * ft_strlen(s1));
	if (s2 == NULL)
		return (0);
	while (i <= ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
