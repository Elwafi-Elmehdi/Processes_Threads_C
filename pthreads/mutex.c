#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutexa = PTHREAD_MUTEX_INITIALIZER;
void *functionMutex();

int main(int argc, char const *argv[])
{
    int rc1, rc2;
    pthread_t thread1, thread2;
    printf("La valeure du counter est: %d \n\n", counter);

    if ((rc1 = pthread_create(&thread1, NULL, &functionMutex, NULL)))
    {
        printf("Error dans la creation du thread 1\n\n");
    }
    if ((rc1 = pthread_create(&thread2, NULL, &functionMutex, NULL)))
    {
        printf("Error dans la creation du thread 2\n\n");
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("La valeure du counter est: %d\n\n", counter);
    return 0;
}

void *functionMutex()
{
    pthread_mutex_lock(&mutexa);
    counter++;
    printf("La valeur est : %d\n\n", counter);
    pthread_mutex_unlock(&mutexa);
}
