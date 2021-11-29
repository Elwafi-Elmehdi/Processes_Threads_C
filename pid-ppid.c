#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid;
    if ((pid = fork()) != 0)
    {
        printf("Bonjour je suis le pere et voila mon PID : %ld \n\n", (long)getpid());
    }
    else
    {
        printf("Bonjour je suis le fils et voila Mon PID : %ld \nLe PID de mon  pere : %ld \n", (long)getpid(), (long)getppid());
    }
    return 0;
}
