/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:07:54 by mabdessm          #+#    #+#             */
/*   Updated: 2024/05/20 15:02:52 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *static_line)
{
	int		i;
	char	*buffer;
	char	*temp;

	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		temp = ft_strjoin(static_line, buffer);
		free(static_line);
		static_line = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (static_line);
}

static char	*parse_line(char *static_line)
{
	int		i;
	char	*res;

	i = 0;
	if (static_line[i] == '\0')
		return (NULL);
	while (static_line[i] && static_line[i] != '\n')
		++i;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (static_line[i] && static_line[i] != '\n')
	{
		res[i] = static_line[i];
		++i;
	}
	if (static_line[i] && static_line[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*get_next_static_line(char *static_line)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (static_line[i] && static_line[i] != '\n')
		++i;
	if (static_line[i] == '\0')
	{
		free(static_line);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(static_line) - i + 1));
	if (!res)
		return (NULL);
	++i;
	while (static_line[i])
		res[j++] = static_line[i++];
	res[j] = '\0';
	free(static_line);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_line = ft_read(fd, static_line);
	if (!static_line)
		return (NULL);
	line = parse_line(static_line);
	static_line = get_next_static_line(static_line);
	return (line);
}
