#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(void)
{
	char	str[] = "Hello";
	char	*ptr;

	ptr = str;
	ft_putstr(ptr - str);
	return (0);
}
