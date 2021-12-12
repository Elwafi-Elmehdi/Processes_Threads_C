#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *afficher_message(void *ptr);

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int retourne1, retourne2;

    retourne1 = pthread_create(&thread1, NULL, afficher_message, (void *)message1);
    retourne2 = pthread_create(&thread2, NULL, afficher_message, (void *)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 retoune la valeure : %d\n\n", message1);
    printf("Thread 2 retoune la valeure : %d\n\n", message2);

    exit(0);
}

void *afficher_message(void *ptr)
{
    char *message;
    message = (char *)ptr;
    printf("%s\n\n", message);
}