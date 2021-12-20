#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define DURREE 5

void *dormir(void *secondes);

int main(int argc, char const *argv[])
{
    pthread_t thread;
    pthread_create(&thread, NULL, dormir, (void *)DURREE);
    pthread_join(thread, NULL);
    return 0;
}

void *dormir(void *secondes)
{
    int s;
    s = (int)secondes;
    sleep(s);
}