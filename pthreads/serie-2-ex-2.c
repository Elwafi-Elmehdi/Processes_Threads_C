#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct parms
{
    char character;
    int counter;
};

void *print(void *structa);

int main(int argc, char const *argv[])
{
    pthread_t thread1;
    pthread_t thread2;
    struct parms A, B;
    A.character = 'x';
    A.counter = 3000;
    B.character = 'o';
    B.counter = 2000;
    pthread_create(&thread1, NULL, print, (void *)&A);
    pthread_create(&thread2, NULL, print, (void *)&B);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

void *print(void *structa)
{
    struct parms *s = (struct parms *)structa;

    for (int i = 0; i < s->counter; i++)
    {
        printf("%s\n", s->character);
    }
}
