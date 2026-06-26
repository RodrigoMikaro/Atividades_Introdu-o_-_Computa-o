// Exercício 7 com inteiros:

/* Dados N >= 0 e uma sequência de n números inteiros, determinar a soma dos númeors pares.
O valor de N será dado como argumento de linha de comando e os N inteiros serão dados na entrada padrão*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[1]) {

    int N = atoi(argv[1]);

    int s = 0;
    
    while (N > 0) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            s += x;
        }
        N--; 
    }

    printf("%d\n", s);
    return 0;
}



// Comandos de seleção:
// if (condição) { corpo }

// if (condição 1) {corpo1} else {corpo 2}

// / e % com a, b possivelmente negativo,
// a / b é o quociente inteiro obtido arredondando para zero.
// O valor de a % b é tal que:
// a = b * (a / b) + (a % b)

