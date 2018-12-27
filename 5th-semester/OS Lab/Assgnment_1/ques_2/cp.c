#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char buffer[1024];
    int fd[2];
    ssize_t count;

    /* Check for insufficient parameters */
    if (argc < 3)
        return -1;
        
    fd[0] = open(argv[1], O_RDONLY);
    if (fd[0] == -1) /* Check if file opened */
        return -1;
        
    fd[1] = open(argv[2], O_WRONLY | O_CREAT);
    if (fd[1] == -1) /* Check if file opened (permissions problems ...) */
    {
        close(fd[0]);
        return -1;
    }
    while ((count = read(fd[0], buffer, sizeof(buffer))) != 0)
        write(fd[1], buffer, count);

    return 0;
}
