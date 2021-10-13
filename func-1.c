// REASON : calculate img of f(x)=(2x+3)(3x^2+2)
// AUTHOR : mehdi
// CREATED DATE : 2021-10-13 16:54:55

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (2 * x + 3) * (3 * pow(x, 2) + 2)
}

int main(int argc, char const *argv[])
{
    double x;

    printf("ENTRE X:\n");
    scanf("%lf", &x);
    printf("F(%.2lf) = %lf", x, f(x));

    return 0;
}
