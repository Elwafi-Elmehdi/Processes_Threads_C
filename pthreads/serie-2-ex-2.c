#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct parms
{
    char character;
    int counter;
};

void *afficher(void *structa)
{
    struct parms *s = (struct parms *)structa;
    for (int i = 0; i < (*s).counter; i++)
    {
        printf("%c\n", (*s).character);
    }
    free(structa);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread1;
    pthread_t thread2;
    struct parms A, B;

    A.character = 'x';
    A.counter = 3000;
    B.character = 'o';
    B.counter = 2000;
    pthread_create(&thread1, NULL, afficher, (void *)&A);
    pthread_create(&thread2, NULL, afficher, (void *)&B);
    // le process pere qui a cree les deux thread n'attend meme pas leur executions d'ou vient interre d'utilisation de fonction pthread_join.
    // La solution est de mettre le process pere en attente jusqu'a l'execution des threads termine.
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    return 0;
}
