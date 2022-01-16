// REASON : Communication entre deux processus en utilisant pipe()
// AUTHOR : mehdi
// CREATED DATE : 2022-01-16 15:55:56

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int fd[2];
    char *message;
    int status = pipe(fd);
    if (status == -1)
    {
        perror("Error PIPE()");
        exit(-1);
    }

    switch (fork())
    {
    case -1:
        perror("Error FORK()");
        exit(-2);
        break;
    case 0:
        close(fd[0]);
        char *message = "Bonjour, je suis processus fils";
        write(fd[1], &message, sizeof(message));
        close(fd[1]);
        break;
    default:
        close(fd[1]);
        read(fd[0], &message, sizeof(message));
        close(fd[0]);
        wait(NULL);
        printf("\nBonjour je suis le processus pere, et j'ai recu \"%s\"", message);
        break;
    }
    return 0;
}
