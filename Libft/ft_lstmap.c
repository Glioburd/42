/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 20:56:07 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/02 21:56:39 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*prev;
	t_list	*origin;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	prev = new;
	origin = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (new == NULL)
			return (NULL);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (origin);
}
