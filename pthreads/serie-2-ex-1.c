#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print(char c);

int main(int argc, char const *argv[])
{
    pthread_t thread;
    char arg_function = "x";
    pthread_create(&thread, NULL, print, (void *)arg_function);
    print("o");
    return 0;
}

void *print(char c)
{
    while (1 == 1)
    {
        printf("%s\n", c);
    }
}
