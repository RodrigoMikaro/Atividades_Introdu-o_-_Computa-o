#include <stdio.h>

int main()
{
    double x;

    while (scanf("%lg", &x) == 1) {
        printf("%lg\n", x);
    }
    
    return 0;
}