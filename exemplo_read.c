/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemplo_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:45:08 by jgiancol          #+#    #+#             */
/*   Updated: 2025/08/01 18:19:18 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main (void)
{
    char    buffer[100];
    ssize_t bytes_read;
    
    bytes_read = read(0, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
    {
        perror("Erro ao ler");
        return (1);
    }
    buffer[bytes_read] = '\0';
    printf("Voce digitou: %s", buffer);
    return (0);
}
