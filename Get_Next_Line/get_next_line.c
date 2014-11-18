#include "libft.h"
#include "get_next_line.h"

char 	*ft_new_search(char **innerBuffer, char **line, int fd)
{
	char		*newBuff;
	char		*tmpBuff;
	char		*tmp;
	int			ret;

	tmpBuff = (char *)malloc(sizeof(BUFF_SIZE + 1));
	ret = read(fd, innerBuffer, BUFF_SIZE);
	if (*innerBuffer == NULL)
		*innerBuffer = tmpBuff;
	else
	{
		newBuff = malloc(ft_strlen(*innerBuffer) + ft_strlen(tmpBuff));
		ft_strcpy(newBuff + ft_strlen(*innerBuffer), tmpBuff);
		free(*innerBuffer);
		*innerBuffer = newBuff;
	}
	if (*tmp = ft_strchr((const char*)innerBuffer, '\n') != NULL)
		return (*innerBuffer);
}

char	**ft_search_end(char **innerBuffer, char **line)
{
	char		*tmp;
	char		*len;
	char		*newBuff;
	if (innerBuffer == NULL)
	{
		if ((tmp = ft_strchr((const char *)innerBuffer, '\n')) != NULL)
		{
			len = (tmp - innerBuffer);
			tmp[0] = '\0';
			ft_strcpy(line, innerBuffer);
			if (len == ft_strlen(innerBuffer))
			{
				free(innerBuffer);
				innerBuffer = NULL;
			}
			else
			{
				newBuff = (char *)malloc(sizeof(ft_strlen(tmp + 1)));
				ft_strcpy_(newBuff, tmp + 1);
				free (innerBuffer);
				innerBuffer = newBuff;
			}
		}
		return (len);
}

int			get_next_line(int const fd, char **line)
{
	static char	*innerBuffer = NULL;

	if (ft_search_end(innerBuffer, *line) != NULL)
	{
		return (1);
	}
	if (ft_new_search(innerBuffer, line, fd) != NULL)
		return (1);
	return (0);
}
