/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:29:34 by dviegas           #+#    #+#             */
/*   Updated: 2025/05/13 15:59:14 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*fill_line(int fd, char *left_c, char *buffer);
static char	*set_line(char *line);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (left_c)
			free(left_c);
		if (buffer)
			free(buffer);
		buffer = NULL;
		left_c = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = set_line(line);
	return (line);
}

static char	*fill_line(int fd, char *left_c, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		if (tmp)
			free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (i == 0 && line[i] == '\0')
		return (NULL);
	if (line[i] == '\n')
	{
		left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
		line[i] = '\0';
		if (*left_c == 0)
		{
			free(left_c);
			left_c = NULL;
		}
		return (left_c);
	}
	else
	{
		return (NULL);
	}
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("./tests/teste.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	i = 0;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("output %d = %s \n", i, line);
		i++;
	}
}
