// REASON : thread allout un tab des entiers aliatoirement
// AUTHOR : mehdi
// CREATED DATE : 2022-01-03 10:54:41

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define randnum(min, max) \
    ((rand() % (int)(((max) + 1) - (min))) + (min))

void *genererTab()
{
    int *tab = malloc(sizeof(int) * 5);
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {

        tab[i] = rand() % 100;
    }
    pthread_exit((void *)tab);
}
int main(int argc, char const *argv[])
{

    void *status;
    int *tableau;
    pthread_t t;
    pthread_create(&t, NULL, genererTab, NULL);
    pthread_join(t, &status);
    tableau = (int *)status;
    for (int i = 0; i < 5; i++)
    {
        printf("Tab[%d] = %d\n", i, tableau[i]);
    }
    return 0;
}
