// REASON : processus qui modifie la valeur d'un variable global
// AUTHOR : mehdi
// CREATED DATE : 2022-01-03 10:07:25

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char *msg = "Bonjour, je suis processus pere";
    if (fork() == 0)
    {
        msg = "Bonjour, je suis processus fils";
    }
    else
    {
        wait(NULL);
        printf("%s", msg);
    }

    return 0;
}
