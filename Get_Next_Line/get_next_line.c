/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 12:07:50 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/19 12:07:53 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

/*
** Lit BUFF_SIZE chars de FD dans innerbuffer, et retourne
** le nombre de caractères lus.
*/
int		ft_read_fd(char **innerBuffer, int fd)
{
	char		*newBuff;
	char		*tmpBuff;
	int			ret;

	tmpBuff = (char *)malloc(sizeof(BUFF_SIZE + 1));
	ret = read(fd, tmpBuff, BUFF_SIZE);
	if (*innerBuffer == NULL)
		*innerBuffer = tmpBuff;
	else
	{
		newBuff = malloc(ft_strlen(*innerBuffer) + ft_strlen(tmpBuff));
		ft_strcpy(newBuff + ft_strlen(*innerBuffer), tmpBuff);
		free(*innerBuffer);
		*innerBuffer = newBuff;
		ft_strcpy(newBuff,*innerBuffer);
	}
	return (ret);
}

int		ft_search_end(char **innerBuffer, char **line, char delimiter)
{
	char		*tmp;
	int			len;
	char		*newBuff;
	if (*innerBuffer != NULL)
	{	
		if ((tmp = ft_strchr(*innerBuffer, delimiter)) != NULL)
		{
			len = (tmp - *innerBuffer);
			tmp[0] = '\0';
			ft_strcpy(*line, *innerBuffer);
			if ((size_t)len == ft_strlen(*innerBuffer))
			{
				free(*innerBuffer);
				*innerBuffer = NULL;
			}
			else
			{
				newBuff = (char *)malloc(sizeof(ft_strlen(tmp + 1)));
				ft_strcpy(newBuff, tmp + 1);
				free (*innerBuffer);
				*innerBuffer = newBuff;
			}
			return (len);
		} 
	}
	return (-1);
}

int get_next_line(int const fd, char **line)
{
	static char	*innerBuffer[BUFF_SIZE];
	int			ret;
	int			read;

	if (BUFF_SIZE <= 0 || !line || (fd < 2 && fd != 0))
		return (-1);
	if(innerBuffer != NULL) 
	{
		ret = ft_search_end(&innerBuffer, line, '\n');
		if (ret != -1) 
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}
	return()
}
/*int get_next_line(int const fd, char **line)
{
	static char*	innerBuffer = NULL;
	int				ret;

	if(innerBuffer != NULL) 
	{
		ret = ft_search_end(&innerBuffer, line, '\n');
		if (ret != -1) {
			//trouvé!
			return 1;
		} 
	}

//si o nest la 'est que l'on a rien trouvé, ou l'on a rien lit

//tant que on a rien trouvé, lire
}
*/