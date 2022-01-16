// REASON : creation d'un pocessus par lapremitive clone()
// AUTHOR : mehdi
// CREATED DATE : 2022-01-04 13:22:52
#define _GNU_SOURCE
#include <linux/sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sched.h>
#include <signal.h>

static int table_multiplication(void *nbr);

int main(int argc, char const *argv[])
{
    int pid_fils, status;
    void *CHILD_STACK = malloc(1024 * 1024);

    if (argc != 2)
    {
        perror("Erreur des argumments");
        exit(1);
    }

    if (CHILD_STACK == NULL)
    {
        printf("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    pid_fils = clone(table_multiplication, CHILD_STACK + (1024 * 1024), SIGCHLD, argv[1]);

    if (pid_fils == -1)
    {
        printf("Erreur clone()");
        exit(2);
    }
    else
    {
        if (wait(&status) == -1)
        {
            perror("wait");
            exit(1);
        }
        else
        {
            free(CHILD_STACK);
            printf("\nTermine.");
        }
    }
    return 0;
}

static int table_multiplication(void *nbr)
{
    printf("\nBonjour je suis le processus fils :\n");
    int N = atoi(nbr);
    for (int i = 1; i < 11; i++)
        printf("%d x %d = %d\n", N, i, N * i);
    printf("\n");
    return 0;
}