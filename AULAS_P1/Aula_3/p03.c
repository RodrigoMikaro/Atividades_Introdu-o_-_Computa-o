// Problema 3:

#include <stdio.h>

int main() {

    int number;
    int sum = 0;

    scanf("%d", &number);

    while (number != 0) {
        sum += number;
        scanf("%d", &number);
    }

    printf("%d", sum);

    return 0;
}