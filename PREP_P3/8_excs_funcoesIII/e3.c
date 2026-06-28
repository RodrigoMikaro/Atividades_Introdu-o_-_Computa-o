#include <stdio.h>
#include <stdlib.h>

void matrix_line_sum (int m, int n, double A[m][n], int i, double* sum);
void matrix_column_product (int m, int n, double A[m][n], int j, double* product);

int main(int argc, char* argv[]) {
    
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    double A[m][n];
    double sum;
    double product;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    matrix_column_product (m, n, A, 1, &product);
    matrix_line_sum (m, n, A, 3, &sum);

    printf("Produto = %lf.\n", product);
    printf("Soma = %lf.\n", sum);
    
    return 0;
}

void matrix_line_sum (int m, int n, double A[m][n], int i, double* sum) {
    (*sum) = 0;

    for (int j = 0; j < n; j++) {
        (*sum) += A[i][j];
    }
}

void matrix_column_product (int m, int n, double A[m][n], int j, double* product) {
    (*product) = 1;

    for (int i = 0; i < m; i++) {
        (*product) *= A[i][j];
    }
}