#include <stdio.h>
#include <stdlib.h>

#define BOARD 8

void total_chess_value (char chess_board[BOARD][BOARD], int* pieces_sum);

int main (void) {
    char chess_board[BOARD][BOARD];

    int sum = 0;

    for (int i = 0; i < BOARD; i++) {
        for (int j = 0; j < BOARD; j++) {
            scanf (" %c|", &chess_board[i][j]);
        }
    }

    total_chess_value (chess_board, &sum);

    printf("Soma total do tabuleiro: %d\n", sum);

    return 0;
}

void total_chess_value (char chess_board[BOARD][BOARD], int* pieces_sum) {
    int value = 0;

    for (int i = 0; i < BOARD; i++) {
        for (int j = 0; j < BOARD; j++) {
            if (chess_board[i][j] == 'P') {
                value += 1;
            }
            else if (chess_board[i][j] == 'C' || chess_board[i][j] == 'B') {
                value += 3;
            }
            else if (chess_board[i][j] == 'T') {
                value += 5;
            }
            else if (chess_board[i][j] == 'D') {
                value += 10;
            }
            else if (chess_board[i][j] == 'R') {
                value += 50;
            }
        }
    }

    (*pieces_sum) = value;

}