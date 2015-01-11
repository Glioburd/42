/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 18:06:25 by gsauvair          #+#    #+#             */
/*   Updated: 2015/01/10 20:48:37 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** "Mini GNL"
** Ouverture du fichier .fdf
*/

int		ft_open(int fd, char **line)
{
	ssize_t		ret;
	char		*buff;
	char		*tmp;

	buff = ft_strnew(BUFF_SIZE + 1);
	*line = malloc(sizeof(**line) * 1);
	**line = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(*line, buff);
		free(*line);
		*line = tmp;
	}
	if (ret == -1)
		return (-1);
	return (0);
}

/*
** Suppression des espaces ave split.
** Conversion de la colonne en int avec atoi.
*/

int		*ft_atoi_width(char *str, int *width)
{
	char	**tab;
	int		*line;

	*width = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[*width])
		*width += 1;
	line = malloc(sizeof(*line) * (*width + 1));
	if (!line)
		return (NULL);
	*width = 0;
	while (tab[*width])
	{
		line[*width] = ft_atoi(tab[*width]);
		*width += 1;
	}
	return (line);
}

/*
** Stock de la map dans un tableau de char avec split en supprimant les '\n'.
** Conversion du tableau de char en tableau de int avec ft_atoi_width (atoi).
** length = ligne
** width = colonne
*/

int		**ft_tab(char **str, int *length, int *width)
{
	int		**inttab;
	char	**chartab;

	if ((chartab = ft_strsplit(*str, '\n')) == NULL)
		return (NULL);
	ft_strdel(str);
	*length = 0;
	while (chartab[*length])
		*length += 1;
	if ((inttab = malloc(sizeof(*inttab) * (*length + 1))) == NULL)
		return (NULL);
	*length = 0;
	while (chartab[*length])
	{
		if ((inttab[*length] = ft_atoi_width(chartab[*length], width)) == NULL)
			return (NULL);
		*length += 1;
	}
	return (inttab);
}
