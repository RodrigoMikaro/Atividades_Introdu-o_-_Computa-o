#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int p = atoi(argv[3]);

    double A[m][n];
    double B[n][p];
    double R[m][p];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            scanf("%lf", &B[i][j]);
        }
    }

    for (int l = 0; l < m; l++){
        for (int c = 0; c < p; c++){
            double product = 0;
            for (int i = 0; i < n; i++){
                product += A[l][i] * B[i][c];
            }
            R[l][c] = product;
        }
    }

    for (int l = 0; l < m; l++){
        for (int c = 0; c < p; c++){
            printf("%lf ", R[l][c]);
        }
        printf("\n");
    }

    return 0;
}