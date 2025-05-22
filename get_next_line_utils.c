/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:16 by dviegas           #+#    #+#             */
/*   Updated: 2025/05/22 10:44:42 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (c)
	{
		while (c[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*str;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (i++ < (lens1 - 1))
		str[i] = s1[i];
	while (j++ < (lens2 - 1))
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_cleanread(char *line, char *buffer)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = ft_newline(line);
	if (sign != -1)
	{
		line[sign + 1] = '\0';
		sign = ft_newline(buffer);
		sign++;
		while (buffer[sign])
			buffer[i++] = buffer[sign++];
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}
