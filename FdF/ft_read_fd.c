/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:12:57 by gsauvair          #+#    #+#             */
/*   Updated: 2014/12/05 16:12:58 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stock	*ft_create_lst(int nb, char nl, t_stock *lst)
{
	t_stock *new_lst;

	if (!lst->prev && !lst->next)
	{
		lst = (t_stock*)malloc(sizeof(t_stock));
		lst->prev = NULL;
		lst->nb = nb;
		return(lst);
	}
	else
	{
		new_lst = (t_stock*)malloc(sizeof(t_stock));
		new_lst->nb = nb;
		new_lst->nl = nl;
		new_lst->prev = lst;
		new_lst->next = NULL;
		lst->next = new_lst;
	}
	return (new_lst);
}

t_stock *ft_return_bol(t_stock *lst)
{
	while (lst->prev != NULL)
		lst = lst->prev;
	lst = lst->next;
	return (lst);
}

t_stock	*ft_go_lst(char *line, t_stock *lst)
{
	char		**ret;

	ret = (char**)ft_strnew(ft_strlen(line));
	ret = ft_strsplit(line, ' ');
	while (*ret)
	{
		lst = ft_create_lst(ft_atoi(*ret), '\0', lst);
		free(*ret);
		ret++;
	}
	return (lst);
}

int		open_f(char *fname)
{
	int		fd;
	char	*line;
	int		ret;
	t_stock *lst;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		ft_error(fname);
	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_error(fname);
		lst = ft_go_lst(line, lst);
		lst = ft_create_lst('\0', '\n', lst);
		free(line);
	}
	lst = ft_return_bol(lst);
	close(fd);
	return (0);
}
