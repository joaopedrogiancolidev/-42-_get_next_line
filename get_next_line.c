/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:10:01 by jgiancol          #+#    #+#             */
/*   Updated: 2025/08/01 18:55:29 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char    buffer[100 + 1];
    ssize_t bytes_read;
	char *line;

	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if(bytes_read == -1)
		return (NULL);
	if (bytes_read == 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	line = ft_strdup(buffer);
	while((line = get_next_line(fd)) != NULL)
		printf("%s", line);
	return (line);
}