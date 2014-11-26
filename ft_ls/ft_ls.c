/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair gsauvair@student.42.fr            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 14:23:15 by gsauvair          #+#    #+#             */
/*   Updated: 2014/11/25 18:57:49 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include "./Libft/libft.h"

DIR		*opendir(const char *path);
int		closedir(DIR *directory);

int main (void)
{
	DIR *dir = NULL;
	struct dirent* fileread = NULL;
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("Erreur");
		exit (1);
	}
	fileread = readdir(dir);
	while ((fileread = readdir(dir)) != NULL)
	{
		if (fileread->d_name[0] != '.')
		{
			ft_putstr(fileread->d_name);
			ft_putchar('\n');
		}
	}
	if (closedir(dir) == -1)
	{
		perror("Erreur");
		exit (1);
	}
	return (0);
}
