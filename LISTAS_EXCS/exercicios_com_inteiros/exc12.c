// Exemplo do algoritmo de Euclides: mdc(24,15) = mdc(15, 9) = mdc(9, 6) = mdc(6, 3) = mdc(3, 3) = mdc (3, 0) = 3

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c;

    int original_a = a;
    int original_b = b;

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    printf("mdc(%d, %d) = %d\n", original_a, original_b, a);

    return 0;
}