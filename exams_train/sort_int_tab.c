#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	smallest;
	int				tmp;

	i = 0;
	while (i < size)
	{
		smallest = i;
		j = i;
		while (j++ < size)
		{
			if (tab[j] < tab[smallest])
				smallest = j;
		}
		tmp = tab[i];
		tab[i] = tab[smallest];
		tab[smallest] = tmp;
		i++;
	}
}

int main ()
{
	int	tab[10] = {1, 4, 6, 8, 7, 3, 4, 9, 10, 5};
	int	i;

	i = 0;
	while (i < 10)
	{
		printf("%d " , tab[i]);
		i++;
	}
	printf("\n");
	i = 0;
	sort_int_tab(tab, 10);
	while (i < 10)
	{
		printf("%d " , tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
