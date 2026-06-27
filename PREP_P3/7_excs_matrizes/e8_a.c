#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

    int n = atoi (argv[1]);
    int Pascal[n][n + 1];
    
    if (n < 1) {
        printf("Insira um número estritamente positivo!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Pascal[i][0] = 0;
    }

    Pascal[0][0] = 0;
    Pascal[0][1] = 1;

    for (int j = 2; j < n + 1; j++) {
        Pascal[0][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n + 1; j++) {
            Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (Pascal[i][j] != 0) {
                printf ("%d ", Pascal[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}