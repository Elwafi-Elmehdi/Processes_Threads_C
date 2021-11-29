#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    printf("The process PID : %ld\n", (long)getpid());
    printf("The parent process PID : %ld", (long)getppid());
    return 0;
}
