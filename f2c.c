#include <stdio.h>
int main(int argc, char const *argv[])
{
    // Declaration des variables
    double c, f;
    // Saisie de la var f
    printf("ENTREZ LA TEMPERATURE EN F");
    scanf("%lf", &f);
    // Calcul de la temperature en degree C
    c = 0.55556l * (f - 32);
    printf("%3lf F = %3lf C \n", f, c);
    return 0;
}
