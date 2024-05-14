/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:07:54 by mabdessm          #+#    #+#             */
/*   Updated: 2024/05/14 16:56:42 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	char		*buffer;
	char		*line;
	static char	*static_line = NULL;
	
	i = 0;
	buffer = NULL;
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (static_line == NULL)
		read(fd, buffer, BUFFER_SIZE);
	else
		buffer = ft_strdup(static_line);		
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line = ft_substr(buffer, 0, i);
			break;
		}
		++i;
	}
	if (!buffer[i])
		line = ft_substr(buffer, 0, i);
	static_line = ft_substr(buffer, i + 1, BUFFER_SIZE);
	free (buffer);
	return(line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	
	fd = open("./test.txt", O_RDONLY);
	printf("first line 1st	 : %s\n", get_next_line(fd));
	printf("second line 2nd	 : %s\n", get_next_line(fd));
	printf("third line 3rd	 : %s\n", get_next_line(fd));
	printf("fourth line 4th	 : %s\n", get_next_line(fd));
	printf("fifth line 5th	 : %s\n", get_next_line(fd));
	printf("sixth line 6th	 : %s\n", get_next_line(fd));
	printf("seventh line 7th : %s\n", get_next_line(fd));
	printf("eighth line 8th	 : %s\n", get_next_line(fd));
	printf("nineth line 9th	 : %s\n", get_next_line(fd));
	printf("tenth line 10th	 : %s\n", get_next_line(fd));
	printf("non existant line: %s\n", get_next_line(fd));
	printf("non existant line: %s\n", get_next_line(fd));
	close(fd);
}
