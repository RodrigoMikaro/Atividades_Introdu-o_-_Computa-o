// Problema 1 da seção de exercícios com inteiros.

#include <stdio.h>

int main() {


    int x;

    scanf("%d", &x);

    while (x != 0) {
        printf("%d ", x * x);
        scanf("%d", &x);
    }

    printf("\n");
    return 0;
}

// Condição: é uma expressão booleana