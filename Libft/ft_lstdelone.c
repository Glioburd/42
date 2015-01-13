/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 19:58:30 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/02 20:16:56 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
	if (lst && *lst)
	{
		if ((*lst)->content)
			del((*lst)->content, (*lst)->content_size);
		ft_memdel((void **)lst);
	}
}
