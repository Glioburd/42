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
	t_stock		*new_lst;
	static int	x;
	static int	y;

	if (!x)
		x += ZOOM;
	if (lst->nl == '\n')
	{
		y += ZOOM;
		x = 0;
	}
	if (!lst)
	{
		lst = first_lst(nb, nl, lst, x, y);
		x += ZOOM;
		return (lst);
	}
	else
	{
		new_lst = ft_new_lst(nb, nl, lst, new_lst, x, y);
		x += ZOOM;
	}
	return (new_lst);
}

t_stock *ft_return_bol(t_stock *lst)
{
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

t_stock	*ft_go_lst(char *line, t_stock *lst)
{
	char		**ret;

	ret = ft_strsplit(line, ' ');
	if (!lst)
		lst = first_lst(ft_atoi(*ret++), '\0', lst, 0, 0);
	while (*ret)
	{
		lst = ft_create_lst(ft_atoi(*ret), '\0', lst);
		free(*ret);
		ret++;
	}
	return (lst);
}

t_stock	*open_f(t_env *e)
{
	char	*line;
	int		ret;
	int		fd;
	t_stock *lst;

	fd = open(e->fname, O_RDONLY);
	if (fd < 0)
		ft_error(e->fname);
	line = NULL;
	lst = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_error(e->fname);
		lst = ft_go_lst(line, lst);
		lst = ft_create_lst('\0', '\n', lst);
		free(line);
	}
	lst = ft_return_bol(lst);
	close(fd);
	return (lst);
}