#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);
    double x = 0, y = 0;


    for(int i = 1; i <= n; i++) {
        scanf("%lg %lg", &x, &y);

        if(x >= 0 && y >=0 && x * x + y * y <= 1) {
            printf("Point (%lg, %lg) belongs, because %lg\n", x, y, x * x + y * y);
        }

        else {
            printf("Point (%lg, %lg) doesnt belong, because %lg\n", x, y, x * x + y * y);

        }

    }


    return 0;
}