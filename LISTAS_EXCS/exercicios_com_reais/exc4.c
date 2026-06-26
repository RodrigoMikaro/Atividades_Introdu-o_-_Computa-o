#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);
    int h_points = 0;

    double x = 0, y = 0;

    for(int i = 1; i <= n; i++){
        
        scanf("%lg %lg", &x, &y);
        
        if ((x <= 0 && y <= 0 && y + x * x + 2 * x - 3 <= 0) || (x >= 0 && y + x * x - 2 * x - 3 <= 0)){
            h_points++;
            printf("(%lg, %lg) belongs.\n", x, y);
        }

        else {
            printf("(%lg, %lg) doesn't.\n", x, y);
        }

    }

    printf("%d out of %d point(s) belong to H.\n", h_points, n);

    return 0;
}