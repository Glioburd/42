/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:19:57 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/08 22:26:08 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	if (size)
	{
		ft_bzero(ret, size);
	}
	return (ret);
}