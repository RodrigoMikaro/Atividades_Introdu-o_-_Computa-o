#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char* argv[]) {
    
    int m = atoi (argv[1]);
    int n = atoi (argv[2]);
    int A[m + 2][n + 2];
    int counter = 1;

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            scanf ("%d", &A[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < m + 2; i++) {
        A[i][n + 1] = -1;
        A[i][0] = -1;
    }

    for (int j = 0; j < n + 2; j++) {
        A[m + 1][j] = -1;
        A[0][j] = -1;
    }

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (A[i][j] == 0) {
                if (((A[i][j + 1] == 0) && (A[i][j - 1] == -1)) || (( (A[i + 1][j] == 0) && (A[i - 1][j] == -1)))) {
                    A[i][j] = counter;
                    counter++;
                }
            }
        }
    }


    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            printf ("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}