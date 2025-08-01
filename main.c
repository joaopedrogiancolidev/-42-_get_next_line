/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:28:18 by jgiancol          #+#    #+#             */
/*   Updated: 2025/08/01 18:54:25 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main() 
{
    int     fd;
    char    buffer[100];
    ssize_t bytes_read;
    char *line;

    fd = open("arquivo.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error ao abrir arquivo");
        return (1);
    }
    line = get_next_line(fd);
    printf("%s", line);
    return (0);
}