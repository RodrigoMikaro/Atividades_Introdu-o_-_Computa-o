#include <stdio.h>
#include <stdlib.h>

void desalocar_matriz (int **M, int m, int n);

int main (int argc, char* argv[]) {
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    int **M;
    M = malloc (m * sizeof (int*));
    for (int i = 0; i < m; i++) {
        M[i] = malloc (n * sizeof (int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    desalocar_matriz (M, m, n);

    return 0;
}

void desalocar_matriz (int **M, int m, int n) {
    for (int i = 0; i < m; i++) {
        free (M[i]);
    }
    free (M);
}

