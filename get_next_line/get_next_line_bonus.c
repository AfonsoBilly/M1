/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:20:47 by adiogo-f          #+#    #+#             */
/*   Updated: 2025/12/19 18:55:51 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (buffer[fd][0] = '\0', NULL);
	while (1)
	{
		if (!*buffer[fd])
		{
			bytes = read_buffer(fd, buffer[fd]);
			if (bytes <= 0)
				break ;
		}
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (buffer[fd][0] = '\0', NULL);
		if (ft_findnl(buffer[fd]))
			return (ft_shiftbuff(buffer[fd]), line);
		*buffer[fd] = '\0';
	}
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
}

/* int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
} */
