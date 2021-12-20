#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct parms
{
    char character;
    int counter;
};

pthread_t thread1;
pthread_t thread2;

int *print(struct parms *structa);

int main(int argc, char const *argv[])
{
    struct parms A, B;
    A.character = "x";
    A.counter = 3000;
    B.character = "o";
    B.counter = 2000;
    pthread_create(&thread1, NULL, print, &A);
    pthread_create(&thread2, NULL, print, &B);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

int *print(struct parms *structa)
{

    for (int i = 0; i < structa->counter; i++)
    {
        printf("%s\n", structa->character);
    }
    return 0;
}
