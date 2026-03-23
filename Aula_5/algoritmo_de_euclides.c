// ------ ALGORITMO DE EUCLIDES ------ //

#include <stdio.h>

int main() {

    int a = 0;
    int b = 0;
    int c = 0;

    // Exemplo: 25 10
    printf("Faremos o MDC dos números:");
    scanf("%d %d", &a, &b);
    
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    // Ciclo 1: 
    // a = 25 . b = 10 . c = 0 . d = 0
    // c = 5
    // a = 10
    // b = 5
    // d = 10

    // Ciclo 2: 
    // a = 10 . b = 5 . c = 5 . d = 10
    // c = 0
    // a = 5
    // b = 0
    // d = 5

    printf("MDC é %d\n", a);
    return 0;
}