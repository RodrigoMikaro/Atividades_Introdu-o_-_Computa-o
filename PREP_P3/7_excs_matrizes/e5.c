#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char* argv[]){

    int n = atoi (argv[1]);
    double A[n][n];
    bool is_of_permutation = true;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf ("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int zero_counter = 0;
        int one_counter = 0;
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) {
                zero_counter++;
            }
            if (A[i][j] == 1) {
                one_counter++;
            }
        }
        if ((zero_counter != n - 1) || (one_counter != 1)) {
            is_of_permutation = false;
        }
    }

    for (int j = 0; j < n; j++) {
        int zero_counter = 0;
        int one_counter = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j] == 0) {
                zero_counter++;
            }
            if (A[i][j] == 1) {
                one_counter++;
            }
        }
        if ((zero_counter != n - 1) || (one_counter != 1)) {
            is_of_permutation = false;
        }
    }

    if (is_of_permutation == true) {
        printf ("A is of permutation.\n");
    }
    else {
        printf ("A is not of permutation.\n");
    }

    return 0;
}