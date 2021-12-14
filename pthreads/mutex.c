#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;
void *function();
pthread_mutex_t mutexa = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char const *argv[])
{
    int rc1, rc2;
    pthread_t thread1, thread2;
    
    return 0;
}

void *function()
{
    pthread_mutex_lock(&mutexa);
    counter++;
    pthread_mutex_unlock(&mutexa);
}
