/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiogo-f <adiogo-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:17:55 by adiogo-f          #+#    #+#             */
/*   Updated: 2025/12/19 18:44:05 by adiogo-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 64
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_findnl(const char *buff);
void	ft_shiftbuff(char *buff);
ssize_t	read_buffer(int fd, char *buffer);
ssize_t	read_buffer(int fd, char *buffer);
ssize_t	read_buffer(int fd, char *buffer);

#endif
