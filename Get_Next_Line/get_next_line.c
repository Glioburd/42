/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:24:02 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/14 17:20:44 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_realloc(char *str, size_t n)
{
	int		i;
	char	*new;

	new = ft_strnew(str, n);
	while (stri[i])
	{
		new[i] = str[i];
		i++;
	}
	free (str);
	return (new);
}



int		get_next_line(int const fd, char **line)
{
	static char	buffer[BUFF_SIZE + 1];
	int			ret;

	if (BUFF_SIZE <= 0 || !line || (fd < 2 && fd != 0))
		return (-1);
	*line = ft_memalloc(sizeof(*line * (BUFF_SIZE + 1)));
	while (ret = read(fd, buffer, BUFF_SIZE))
		buferf[ret] = '\0';

}
/*{
	static char	buffer[BUFF_SIZE + 1];
	int			ret;	
	if (buffer < 0 || !line || fd != 0)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	*line = (char*)ft_memalloc(sizeof (*line) * BUFF_SIZE + 1);
	while (ret)
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		while (buffer != '\n')
		{
			buff++;
		}
		buff = '\0';
	}
	return (0);
}*/


strjoin
strnew strcpy
