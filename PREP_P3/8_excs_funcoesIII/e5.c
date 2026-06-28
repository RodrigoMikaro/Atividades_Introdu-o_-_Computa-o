#include <stdio.h>
#include <stdlib.h>

void MAX (int n, int A[n][n], int* k, int* l, int* c);

int main (int argc, char* argv[]) {
    int n = atoi (argv[1]);
    int A[n][n];
    int k;
    int l;
    int c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf ("%d", &A[i][j]);
        }
    }

    printf ("ELEM | LINHA | COLUNA\n");

    for (int r = 0; r < n * n; r++) { 
        MAX (n, A, &k, &l, &c);
        printf ("  %d  |   %d   |   %d  \n", k, l, c);
        A[l][c] = -1;
    }

    return 0;
}

void MAX (int n, int A[n][n], int* k, int* l, int* c) {
    (*k) = A[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] >= (*k)) {
                (*k) = A[i][j];
                (*l) = i;
                (*c) = j;
            }
        }
    }
}
