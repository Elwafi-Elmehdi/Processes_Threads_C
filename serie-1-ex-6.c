// REASON : creation d'un thread qui dort
// AUTHOR : mehdi
// CREATED DATE : 2022-01-03 09:47:12

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>

void *dormir(void *duree)
{
    int *d = (int *)duree;
    sleep(*d);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    int nbr;
    if (argc = !2)
    {
        printf("Nombre d'arguments invalid");
        exit(1);
    }
    nbr = atoi(argv[1]);
    pthread_create(&thread, NULL, dormir, (void *)&nbr);
    pthread_join(thread, 0);
    return 0;
}
