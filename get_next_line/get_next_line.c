
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	line = NULL;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (buffer[0] = '\0', NULL);
	while (*buffer || (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes > 0)
			buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (buffer[0] = '\0', NULL);
		if (ft_findnl(buffer))
			return (ft_shiftbuff(buffer), line);
		*buffer = '\0';
	}
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}