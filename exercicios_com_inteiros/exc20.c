#include <stdio.h>
#include <stdlib.h>


int to_the_power(int number, int exponent);


int main() {

    for (int i = 1000; i <10000; i++) {

        int first_two = 0;
        int last_two = 0;
        int root = 0;
        int number = i;
        int r;
        int exponent = 0;

        for (int j = 1; j * j <= i; j++) {
            if (j * j == i) {
                root = j;
                break;
            }
        }

        for (int t = 1; t < 3; t++) {
            r = number % 10;
            number /= 10;
            last_two += r * to_the_power(10, exponent);
            exponent++;
        }

        exponent = 0;

        for (int t = 3; t < 5; t++) {
            r = number % 10;
            number /= 10;
            first_two += r * to_the_power(10, exponent);
            exponent++;
        }

        if (root == 0) {
            continue;
        }
        if (root == first_two + last_two) {
            printf("%d = %d + %d\n", root, first_two, last_two);
        }

    }

    return 0;
}


int to_the_power(int number, int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= number;
    }
    
    return result;
}