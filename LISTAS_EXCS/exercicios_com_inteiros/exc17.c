#include <stdio.h>
#include <stdlib.h>


int to_the_power(int number, int power);


int main(int argc, char *argv[]) {

    int decimal = atoi(argv[1]);
    int original_decimal = decimal;
    int weight;
    int exponent = 0;
    int binary = 0;

    while(decimal > 0) {
        weight = decimal % 2;
        decimal /= 2;
        binary += weight * to_the_power(10, exponent);
        exponent++;
    }

    printf("%d in decimal is equivalent to %d in binary.\n", original_decimal, binary);

    return 0;
}

int to_the_power(int number, int power) {

  int result = 1;

  for (int i = 0; i < power; i++) {
    result *= number;
  }

  return result;
}
