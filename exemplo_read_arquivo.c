#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    buffer[100];
    ssize_t bytes_read;

    fd = open("arquivo.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error ao abrir arquivo");
        return (1);
    }
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
    {
        perror("Erro ao ler arquivo");
        close(fd);
        return (1);
    }
    buffer[bytes_read] = '\0';
    printf("Conteudo lido: %s\n", buffer);

    close(fd);
    return (0);
}

// buffer dinamico com free (numero muito grande(8MB a 16MB))
// 
