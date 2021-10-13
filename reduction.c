// REASON : calculate redution offer prise from init prise
// AUTHOR : mehdi
// CREATED DATE : 2021-10-13 16:20:09

#include <stdio.h>
int main(int argc, char const *argv[])
{
    double initPrise, offrePrise;
    short percentage = 10;

    printf("ENTRER THE INITIAL PRISE: \n");
    scanf("%lf", &initPrise);

    offrePrise = initPrise - (initPrise / percentage);
    printf("THE OFFER PRISE IS: %lf \n", offrePrise);

    return 0;
}
