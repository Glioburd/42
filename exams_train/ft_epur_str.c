/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 14:20:24 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/16 17:05:16 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}

}

char		*ft_epur_str(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			str[j] = str[i];
			j++;
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
			{
				str[j] = ' ';
				j++;
			}
		}
		i++;
	}
	str[j] = '\0';
	if (str[j - 1] == ' ')
		str[j - 1] = '\0';
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_epur_str(argv[1]);
		ft_putstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
