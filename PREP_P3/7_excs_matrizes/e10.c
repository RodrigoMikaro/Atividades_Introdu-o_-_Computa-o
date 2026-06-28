#include <stdio.h>
#include <stdlib.h>
#define BOARD 8

int main (void) {
    
    int D[BOARD + 2][BOARD + 4];
    char black_case;
    char C[BOARD + 2][BOARD + 4];
    
    for (int i = 0; i < BOARD; i++) {
        for (int j = 2; j < BOARD + 2; j++) {
            scanf("%d", &D[i][j]);
        }
    }
    
    for (int i = 0; i < BOARD; i++) {
        D[i][0] = -1;
        D[i][1] = -1;
        D[i][10] = -1;
        D[i][11] = -1;
    }

    for (int j = 0; j < BOARD + 4; j++) {
        D[BOARD][j] = -1;
        D[BOARD + 1][j] = -1;
    }

    for (int i = 0; i < BOARD; i++) {
        for (int j = 2; j < BOARD + 2; j++) {
            if (D[i][j] == -1) {
                // Se esq1 é preta:
                if (D[i + 1][j - 1] == -1) {
                    // Se dir1 é preta:
                    if (D[i + 1][j + 1] == -1) {
                        black_case = 'c';
                    }
                    // Se dir1 é vazio:
                    else if (D[i + 1][j + 1] == 0) {
                        black_case = 'b';
                    }
                    // Se dir1 é branco:
                    else if (D[i + 1][j + 1] == 1) {
                        if (D[i + 2][j + 2] == 0) {
                            black_case = 'a';
                        }
                        else {
                            black_case = 'c';
                        }
                    }
                }

                // Se esq1 é vazio:
                else if (D[i + 1][j - 1] == 0) {
                    // Se dir1 é branco:
                    if (D[i + 1][j + 1] == 1) {
                        // Se dir2 é vazio:
                        if (D[i + 2][j + 2] == 0) {
                            black_case = 'a';
                        }
                        else {
                            black_case = 'b';
                        }
                    }

                    else {
                        black_case = 'b';
                    }
                }

                // Se esq1 é branco:
                else if (D[i + 1][j - 1] == 1) {
                    if (D[i + 2][j - 2] == 0) {
                        black_case = 'a';
                    }
                    else {
                        if (D[i + 1][j + 1] == -1) {
                            black_case = 'c';
                        }
                        else if (D[i + 1][j + 1] == 0) {
                            black_case = 'b';
                        }
                        else {
                            if (D[i + 2][j + 2] == 0) {
                                black_case = 'a';
                            }
                            else {
                                black_case = 'c';
                            }
                        }
                    }

                }
                C[i][j] = black_case;
            }
        }
    }

    for (int i = 0; i < BOARD; i++) {
        for (int j = 2; j < BOARD + 2; j++) {
            if (D[i][j] == -1) {
                printf ("%c ", C[i][j]);
            }
            else if (D[i][j] == 1) {
                printf ("1 ");
            }
            else {
                printf ("_ ");
            }
        }
        printf("\n");
    }

    return 0;
}