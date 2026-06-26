#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char* argv[]){
    
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    double A[m][n];
    double X[n][1];
    double B[m][1];
    bool is_solution = true;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        scanf("%lf", &X[i][0]);
    }

    for (int i = 0; i < m; i++){
        scanf("%lf", &B[i][0]);
    }

    for (int l = 0; l < m; l++){
        for (int c = 0; c < 1; c++){
            double dot_product = 0;
            for (int s = 0; s < n; s++){
                dot_product += A[l][s] * X[s][c];
            }
            if (B[l][c] != dot_product){ // daria para colocar fabs nessa linha
                is_solution = false;
            }
        }
    }
    
    if (is_solution == true){
        printf("A * X = B\n");
    }
    else {
        printf("A * X != B\n");
    }

    return 0;
}