#include <stdio.h>
#include <stdlib.h>

int main(void){

    double x, y;
    int belonging_numbers = 0;
    int numbers_total = 0;

    while(scanf("%lg %lg", &x, &y) == 2) {
        if (x >= 0 && y >= 0 && x * x + y * y <= 1) {
            belonging_numbers++;
        }
        numbers_total++;
    }

    printf("%lg\n", 1.0 * belonging_numbers / numbers_total);
    
    return 0;
}