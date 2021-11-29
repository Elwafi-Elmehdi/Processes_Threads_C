#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)

int main(int argc, char *argv[])
{
    for (int i = 2; i < argc; i++)
    {
        printf("%d\n\n", MIN(atoi(argv[i]), atoi(argv[i - 1])));
    }
    return 0;
}
