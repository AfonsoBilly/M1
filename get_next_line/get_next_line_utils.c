#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i)
}

char    *ft_strchr(const char *s, int c)
{
    size_t i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    if (c == '\0')
        return ((char *)&s[i]);
    return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}