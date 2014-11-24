/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 21:22:46 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/24 21:22:47 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** Lit BUFF_SIZE chars de FD dans innerbuffer, et retourne
** le nombre de caractères lus.
*/

static int	ft_read_fd(char **str, int fd)
{
	int		ret;
	char	*tmpBuff;

	tmpBuff = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, tmpBuff, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	tmpBuff[ret] = 0;
	*str = ft_strjoin(*str, tmpBuff);
	ft_strdel(&tmpBuff);
	return (ret);
}

/*
** 
*/

static int	ft_fill(char **line, char **str, char *ptr)
{
	int		ret;

	ret = 0;
	if (*ptr == '\n')
		ret = 1;
	*ptr = 0;
	*line = ft_strjoin("", *str);
	*str = ft_strjoin(ptr + 1, "");
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char *str;
	char		*ptr;
	int			size;
	int			ret;

	if (BUFF_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (str == 0)
		str = "";
	size = BUFF_SIZE;
	while (1)
	{
		ptr = str;
		while (*ptr || size < BUFF_SIZE)
		{
			if (*ptr == '\n' || *ptr == -1 || *ptr == 0)
			{
				ret = ft_fill(line, &str, ptr);
				return (ret);
			}
			ptr++;
		}
		size = ft_read_fd(&str, fd);
		if (size == -1)
			return (-1);
	}
	return (0);
}
