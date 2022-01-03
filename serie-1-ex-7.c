// REASON : thread qui affiche un tableau d'entiers
// AUTHOR : mehdi
// CREATED DATE : 2022-01-03 10:07:25

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
void *afficher_tableau(void *tableau)
{
    int *tab = (int *)tableau;
    for (int i = 0; i < 5; i++)
    {
        printf("Bonjour, je suis le thread secondaire, et voila ce que j'ai recu du thread principale");
        printf("Tab[%d] = %d\n", i, tab[i]);
    }
}
int main(int argc, char const *argv[])
{
    int tab[5];
    pthread_t t;
    for (int i = 0; i < 5; i++)
    {
        tab[i] = i * 2;
    }
    pthread_create(&t, NULL, afficher_tableau, (void *)&tab);
    pthread_join(t, 0);
    return 0;
}
