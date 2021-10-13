#include <stdio.h>
int main(int argc, char const *argv[])
{
    // Declaration des variables
    double c, f;
    // Saisie de la var f
    printf("ENTREZ LA TEMPERATURE EN c \n");
    scanf("%lf", &c);
    // Calcul de la temperature en degree C
    f = (c / 0.55556l) + 32;
    printf("%3lf C = %3lf F \n", c, f);
    return 0;
}