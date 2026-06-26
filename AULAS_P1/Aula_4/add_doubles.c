#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = a + b;
    printf("%g + %g = %g\n", a, b, c);
    return 0;
}