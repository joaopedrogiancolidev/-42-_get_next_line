/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:01:04 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/01 15:15:45 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*extract_line(char **stock)
{
	int		len;
	char	*line;
	char	*new_stock;

	if (*stock == NULL || **stock == '\0')
		return (NULL);
	len = 0;
	while ((*stock)[len] && (*stock)[len] != '\n')
		len++;
	if ((*stock)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *stock, len);
	line[len] = '\0';
	new_stock = ft_strdup(*stock + len);
	free(*stock);
	*stock = new_stock;
	return (line);
}

static int	read_to_stock(int fd, char **stock, char *buf)
{
	ssize_t	bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes > 0)
	{
		buf[bytes] = '\0';
		*stock = ft_strjoin_free(*stock, buf);
		if (!*stock)
			return (0);
	}
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD];
	char		*buf;
	ssize_t		bytes;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (stock[fd] == NULL)
		stock[fd] = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stock[fd], '\n') && bytes > 0)
		bytes = read_to_stock(fd, &stock[fd], buf);
	free(buf);
	if (bytes < 0 || (bytes == 0 && (!stock[fd] || *stock[fd] == '\0')))
	{
		if (stock[fd])
			free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&stock[fd]));
}
