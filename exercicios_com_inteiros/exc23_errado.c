#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int power(int number, int exponent);


int main(int argc, char *argv[]) {

    int number = atoi(argv[1]);
    int spare_number = number;
    int original_number = number;
    int l = 0; // we still have to determine the counter from the left
    int r = 1;
    int left_digit;
    int right_digit;

    while (spare_number > 10) {
        spare_number /= 10;
        l++;
    }

    while (l >= r) {
        left_digit = number / power(10, l);
        right_digit = number % 10;

        number -= left_digit * power(10, l);
        number /= 10;

        printf("Corte %d: %d\n", r, number);

        if (left_digit != right_digit) {
            printf("%d is not a palindrome.\n", original_number);
            return 0;
        }

        l-= 2;
        r++;
    }

    printf("%d is a palindrome.\n", original_number);

    return 0;
}



int power(int number, int exponent) {

    int result = 1;

    for (int i = 1; i <= exponent; i++) {
        result *= number;
    }

    return result;
}