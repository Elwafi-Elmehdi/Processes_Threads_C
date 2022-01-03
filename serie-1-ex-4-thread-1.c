// REASON : thread qui modifie la valeur d'un variable global
// AUTHOR : mehdi
// CREATED DATE : 2022-01-03 10:07:25

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>

void *modif(void *message)
{
    char *msg = (char *)message;
    msg = "Bonjour, je suis thread secondaire";
}

int main(int argc, char const *argv[])
{
    char *msg = "Bonjour, je suis thread principal\n";
    pthread_t t;
    pthread_create(&t, NULL, modif, (void *)&msg);
    pthread_join(t, 0);
    printf("%s", msg);
    return 0;
}