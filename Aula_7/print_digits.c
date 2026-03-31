// Imprime os dígitos de um número:

#include <stdio.h>

int main() {

    int a;
    int r;

    scanf("%d", &a);

    while(a > 0) {
        r = a % 10;
        printf("%d\n", r);
        a = a / 10;
    }

    return 0;
}