#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        exit(-1);
    }
    int status;
    pid_t pid;
    system("clear");

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        pid = fork();
        if (pid == -1)
        {
            // Pas de memoire pour creer des processus
            exit(-1);
        }
        else if (pid != 0)
        {
            continue;
        }
        else
        {
            sleep(2 * i);
            printf("Je suis le fils : %d \net voila mon pere : %d \n\n", (long)getpid(), (long)getppid());
            exit(i);
        }
    }

    while (1)
    {
        int pidfils = wait(&status);
        if (pidfils == -1)
        {
            break;
        }
        else
        {
            printf("Processus Termine: %d avec le code status : %d\n\n", pidfils, WEXITSTATUS(status));
        }
    }

    return 0;
}