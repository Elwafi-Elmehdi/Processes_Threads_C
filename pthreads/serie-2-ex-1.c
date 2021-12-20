#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print(void *c);

int main(int argc, char const *argv[])
{
    pthread_t thread;
    char *arg_function = "x";
    pthread_create(&thread, NULL, print, (void *)arg_function);
    print("o");
    return 0;
}

void *print(void *c)
{
    char *character;
    character = (char *)c;

    while (1 == 1)
    {
        printf("%s\n", character);
    }
}
