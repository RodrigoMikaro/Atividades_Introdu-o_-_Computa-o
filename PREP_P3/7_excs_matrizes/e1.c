#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    double A[m][n];
    double V[n];
    double R[m];
    double product = 0;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        scanf("%lf", &V[i]);
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            product += A[i][j] * V[j];
        }
        R[i] = product;
        product = 0;
    }

    for (int i = 0; i < m; i++){
        printf("%lf\n", R[i]);
    }

    return 0;
}