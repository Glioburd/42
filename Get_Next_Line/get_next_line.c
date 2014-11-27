/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:23:30 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/25 16:23:47 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read_fd(char **str, int fd)
{
	int		ret;
	char	*tmpbuff;

	tmpbuff = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, tmpbuff, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	tmpbuff[ret] = 0;
	*str = ft_strjoin(*str, tmpbuff);
	ft_strdel(&tmpbuff);
	return (ret);
}

static int	ft_fill(char **line, char **str, char *ptr)
{
	int		ret;

	ret = 0;
	if (*ptr == '\n')
		ret = 1;
	*ptr = 0;
	*line = ft_strdup(*str);
	*str = ft_strdup(ptr + 1);
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char *str;
	char		*ptr;
	int			size;

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
			if (*ptr == '\n' || *ptr == -1 || *ptr == '\0')
				return (ft_fill(line, &str, ptr));
			ptr++;
		}
		size = ft_read_fd(&str, fd);
		if (size == -1)
			return (-1);
	}
	return (0);
}
