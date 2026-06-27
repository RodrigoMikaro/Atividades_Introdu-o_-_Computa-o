#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char* argv[]) {
    
    int n = atoi(argv[1]);
    double A[n][n];
    bool is_magic_square = true;
    double sums_columns[n];
    double sums_lines[n];
    double sum_main_diagonal = 0;
    double sum_sec_diagonal = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf ("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += A[i][j];
        }
        sums_lines[i] = sum;
    }

    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i][j];
        }
        sums_columns[j] = sum;
    }
    
    for (int k = 0; k < n; k++) {
        sum_main_diagonal += A[k][k];
        sum_sec_diagonal += A[k][n - k - 1];
    }

    if (sum_main_diagonal != sum_sec_diagonal) {
        is_magic_square = false;
    }

    for (int k = 0; k < n; k++) {
        if ((sum_main_diagonal != sums_lines[k]) || (sum_main_diagonal != sums_columns[k])) {
            is_magic_square = false;
            break;
        }
    }

    if (is_magic_square == true) {
        printf("A is a magic square.\n");
    }
    else {
        printf("A is NOT a magic square.\n");
    }

    return 0;
}