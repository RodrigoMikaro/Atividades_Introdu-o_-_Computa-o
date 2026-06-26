// Escrever um programa que recebe um inteiro positivo e que imprime seus dígitos:

#include <stdio.h>

int main() {

    int N, q, r;

    scanf("%d", &N);

    while (N > 0) {
        q = N / 10;
        r = N % 10;
        printf("%d\n", r);

        N = q;
    }


    return 0;
}


// Em matemática:
// a, b naturais com b != 0,
// o algoritmo da divisão fornece q e r naturais
// tais que a = b * q + r
// e 0 <= r < b
// ademais, tais q e r são univocamente definidos.


// Em C, se a, b são naturais:
// e b != 0
// q é dado por a / b
// e r é dado por a % b

// 2166 = (216) * 10 + 6
// 216 = 21 * 10 + 6
// 21 = 2 * 10 + 1
// 2 

// Escopo de uma variável:
// parte de um programa em que aquela variável pode ser utilizada.