/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:20 by dviegas           #+#    #+#             */
/*   Updated: 2025/05/22 11:43:11 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (ft_newline(line) == -1)
	{
		if (buffer[0] == '\0')
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes == 0)
					return (line);
				free(line);
				return (NULL);
			}
			buffer[bytes] = '\0';
		}
		line = ft_strjoin(line, buffer);
		ft_cleanread(line, buffer);
	}
	return (line);
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

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	i = 1;
	while (i < 68)
	{
		line = get_next_line(fd);
		printf("output %d = %s \n", i, line);
		free(line);
		i++;
	}
	close(fd);
}
