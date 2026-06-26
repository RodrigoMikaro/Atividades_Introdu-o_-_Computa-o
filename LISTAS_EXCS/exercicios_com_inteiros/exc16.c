

#include <stdio.h>
#include <stdlib.h>


int to_the_power(int number, int power);


int main(int argc, char *argv[]) {

    int binary = atoi(argv[1]);
    int original_binary = binary;
    int weight;
    int decimal = 0;
    int exponent = 0;

    while (binary > 0) {
        weight = binary % 10;
        binary = binary / 10;
        decimal += weight * to_the_power(2, exponent);
        exponent++;
    }

    printf("%d in binary is equivalent to %d in the decimal system.\n", original_binary, decimal);

    return 0;
}


int to_the_power(int number, int power) {

    int result = 1;

    for (int i = 0; i < power; i++) {
        result *= number;
    }

    return result;
}
