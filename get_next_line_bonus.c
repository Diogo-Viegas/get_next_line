/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:29:34 by dviegas           #+#    #+#             */
/*   Updated: 2025/05/19 15:34:42 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*fill_line(int fd, char *left_c, char *buffer);
char	*set_line(char *line);
char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*left_c[MAX_FD];
	char		*line;
	char		*buffer;
	char		*old_left;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	old_left = left_c[fd];
	left_c[fd] = fill_line(fd, left_c[fd], buffer);
	if (!left_c[fd] && old_left)
		free(old_left);
	free(buffer);
	buffer = NULL;
	if (!left_c[fd])
		return (NULL);
	line = left_c[fd];
	left_c[fd] = set_line(line);
	return (line);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	*fill_line(int fd, char *left_c, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		left_c = join_and_free(left_c, buffer);
		if (!left_c)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*set_line(char *line)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
	{
		left_c = ft_substr(line, i + 1, ft_strlen(line) - i);
		line[i + 1] = '\0';
		if (left_c && *left_c == 0)
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

char	*ft_strchr(char *s, int c)
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

// #include <errno.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	int		i;
// 	char	*line;
// 	char	*line2;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erro ao abrir o arquivo");
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 		printf("output file1: %d = %s        |      output file2: %s \n", i,
// 			line, line2);
// 		free(line);
// 		free(line2);
// 		i++;
// 	}
// }
