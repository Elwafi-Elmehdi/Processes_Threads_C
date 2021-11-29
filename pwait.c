#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        pid_t pid = fork();
        if (getppid() != 0)
        {
            printf("Je suis le fils : %d", pid);
            sleep(2 * i);
            exit(i);
        }
    }
    // while (wait( == -1)
    // {
    //     int pid = wait();
    //     printf("%d", pid);
    // }

    return 0;
}