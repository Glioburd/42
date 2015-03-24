/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 16:01:37 by gsauvair          #+#    #+#             */
/*   Updated: 2015/02/22 16:12:41 by gsauvair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int start, int end)
{
	int	i;
	int	*range;
	int	size;

	i = 0;
	if (start < end)
		size = end - start;
	else
		size = start - end;
	if (start > 0 || end > 0)
		range = (int *)malloc(sizeof(int) * (size));
	else
		range = (int *)malloc(sizeof(int) * (size + 1));
	if (range == NULL)
		return (0);
		while (i <= (size))
	{
		range[i] = start;
		i++;
		if (start < end)
			start++;
		else
		{
			start--;
		}
	}
	return(range);
}

int main(void)
{
	int *tab;
	int i;

	i = 0;
	tab = ft_range(1, 3);
	printf("(1, 3)\n");
	while (i <= 3)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("________\n");
	tab = ft_range(-1, 2);
	printf("(-1, 2)\n");
	while (i <= 3)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("________\n");
	tab = ft_range(0, 0);
	printf("(0, 0)\n");
	while (i <= 2)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("________\n");
	tab = ft_range(0, -3);
	printf("(0, -3)\n");
	while (i <= 4)
	{
		printf("%d: %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
