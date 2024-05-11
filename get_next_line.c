/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:07:54 by mabdessm          #+#    #+#             */
/*   Updated: 2024/05/11 17:26:03 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*res;
	static char	*static_res;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	res = //function to get next line;
	free(buffer);
	if (!res)
		return (NULL);
	static_res = //function to keep the static line;
	return (res);
}
int	main(int argc, char **argv)
{
	printf("%s", get_next_line(argv[1]));
}