/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:07:15 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/15 18:57:42 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*dst;

	dst = s1;
	while (n)
	{
		*dst = *s2;
		dst++;
		if (*s2)
		{
			s2++;
		}
		n--;
	}
	return (s1);
}
