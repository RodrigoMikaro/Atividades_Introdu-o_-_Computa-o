#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char* argv[]) {

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    double A[m][n];
    int null_line_counter = 0;
    int null_column_counter = 0;
    bool is_null = true;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf ("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        is_null = true;
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                is_null = false;
            }
        }
        if (is_null == true) {
            null_line_counter += 1;
        }
    }
    
    for (int j = 0; j < n; j++) {
        is_null = true;
        for (int i = 0; i < m; i++) {
            if (A[i][j] != 0) {
                is_null = false;
            }
        }
        if (is_null == true) {
            null_column_counter += 1;
        }
    }

    printf("A tem %d linha(s) nula(s) e %d coluna(s) nula(s).\n", null_line_counter, null_column_counter);

    return 0;
}