
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}

int	ft_findnl(const char *buff)
{
	int	i;

	i = 0;
	while (buff && buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_shiftbuff(char *buff)
{
	int	i;
	int	j;

	if (!buff)
		return ;
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	j = 0;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
}