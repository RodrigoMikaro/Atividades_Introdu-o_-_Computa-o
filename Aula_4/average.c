#include <stdio.h>

int main()
{
    int x, s = 0, N = 1;

    while (scanf("%d", &x) == 1) {
        s += x;
        N++;
    }

    printf("Average: %lg\n", 1.0 * s / N);
    
    return 0;
}