/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:20 by dviegas           #+#    #+#             */
/*   Updated: 2025/05/22 11:19:08 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (ft_newline(line) == -1)
	{
		if (buffer[fd][0] == '\0')
		{
			bytes = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes <= 0)
			{
				if (bytes == 0)
					return (line);
				free(line);
				return (NULL);
			}
			buffer[fd][bytes] = '\0';
		}
		line = ft_strjoin(line, buffer[fd]);
		ft_cleanread(line, buffer[fd]);
	}
	return (line);
}

// #include <errno.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(void)
// {
// 	int fd;
// 	int fd2;
// 	int i;
// 	char *line;
// 	char *line2;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test1.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erro ao abrir o arquivo");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 		printf("output file1: %d = %s        |      output file2: %s", i, line,
// 			line2);
// 		free(line);
// 		free(line2);
// 		i++;
// 	}
// }