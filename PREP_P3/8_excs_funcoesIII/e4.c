#include <stdlib.h>
#include <stdio.h>

void switch_values (double* a, double* b);
void switch_lines (int i1, int i2, int m, int n, double A[m][n]);

int main (int argc, char* argv[]) {
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    double A[m][n];

    int i1 = atoi(argv[3]);
    int i2= atoi(argv[4]);

    double variable_A = 3.1415;
    double variable_B = 2.718;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf ("%lf",  &A[i][j]);
        }
    }

    switch_lines(i1, i2, m, n, A);

    printf("\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void switch_values (double* a, double* b) {
    double original_a = (*a);
    double original_b = (*b);

    (*a) = original_b;
    (*b) = original_a;
}

void switch_lines (int i1, int i2, int m, int n, double A[m][n]) {
    for (int j = 0; j < n; j++) {
        switch_values (&A[i1][j], &A[i2][j]);
    }
}