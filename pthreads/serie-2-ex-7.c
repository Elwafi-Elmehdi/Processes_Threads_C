// REASON : creation d'un pocessus par lapremitive clone()
// AUTHOR : mehdi
// CREATED DATE : 2022-01-04 13:22:52
#include <linux/sched.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sched.h>

int *table_multiplication(void *nbr);

int main(int argc, char const *argv[])
{
    int N;
    int pid_fils;
    if (argc != 2)
    {
        exit(1);
    }
    N = atoi(argv[1]);
    pid_fils = clone(table_multiplication, malloc(1024 * 1024), CLONE_NEWUTS | SIGCHLD, (void *)&N);

    return 0;
}

int *table_multiplication(void *nbr)
{
    int tab[11];
    int *nombre = (int *)nbr;
    for (int i = 1; i < 11; i++)
        tab[i] = i * (*nombre);
    return tab;
}