#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *argv[]) {
    int n = atoi(argv[1]);
    int original_n = n;
    int remainder = 0;
    int inverted = 0;

    while (n > 0) {
        remainder = n % 10;
        inverted = inverted * 10 + remainder;
        n = n / 10;
    }

    if (inverted == original_n) {
        printf("%d is a palindrome.\n", original_n);
    }
    else {
        printf("%d is NOT a palindrome.\n", original_n);
    }

    return 0;
}