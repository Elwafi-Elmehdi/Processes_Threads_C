#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void fillTab(int tab[3]);
void printTab(int tab[3]);

int main(int argc, char *argv[])
{
    int fd[2];
    int tab[3], tab2[3];

    int status = pipe(fd);

    if (status == -1)
    {
        printf("Erreur PIPE()");
        return 1;
    }

    switch (fork())
    {
    case -1:
        printf("Erreur FORK()");
        return 1;
    case 0:
        close(fd[0]);
        fillTab(tab);
        write(fd[1], tab, sizeof(tab));
        close(fd[1]);
        printf("Par processus fils. \n\n");
        break;

    default:
        close(fd[1]);
        read(fd[0], tab2, sizeof(tab));
        close(fd[0]);
        printTab(tab2);
        printf("Par processus pere. \n\n");
        break;
    }

    return 0;
}

void printTab(int tab[3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("TAB[%d] = %d\n", i, tab[i]);
    }
}

void fillTab(int tab[3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("TAB[%d] = ", i);
        scanf("%d", &tab[i]);
    }
}