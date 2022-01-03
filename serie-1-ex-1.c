#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)

int somme(int argc, char *argv[]);
int max(int argc, char *argv[]);
int min(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int pid, pid1, pid2;

    if ((pid = fork()) != 0)
    {
        printf("Creation des 3 processus!\n\n");
        if ((pid1 = fork()) != 0)
        {
            if ((pid2 = fork()) == 0)
            {
                printf("Bonjour je suis le 3eme fils et voila Mon PID : %ld \nLe PID de mon  pere : %ld \n\n", (long)getpid(), (long)getppid());
                printf("Le Min est : %d \n\n", min(argc, argv));
            }
        }
        else
        {
            printf("Bonjour je suis le 2eme fils et voila Mon PID : %ld \nLe PID de mon  pere : %ld \n\n", (long)getpid(), (long)getppid());
            printf("Le Max est : %d \n\n", max(argc, argv));
        }
    }
    else
    {
        printf("Bonjour je suis le 1er fils et voila Mon PID : %ld \nLe PID de mon  pere : %ld \n\n", (long)getpid(), (long)getppid());

        printf("La somme : %d \n\n", somme(argc, argv));
    }
    return 0;
}

int somme(int argc, char *argv[])
{
    int resultat = 0;
    for (int i = 1; i < argc; i++)
    {
        resultat += atoi(argv[i]);
    }
    return resultat;
}

int max(int argc, char *argv[])
{
    int max = 0;
    for (int i = 2; i < argc; i++)
    {
        max = MAX(atoi(argv[i]), atoi(argv[i - 1]));
    }
    return max;
}

int min(int argc, char *argv[])
{
    int min = 0;
    for (int i = 2; i < argc; i++)
    {
        min = MIN(atoi(argv[i]), atoi(argv[i - 1]));
    }
    return min;
}