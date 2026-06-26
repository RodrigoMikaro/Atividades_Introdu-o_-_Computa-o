#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    int a_squared = a * a;
    int b_squared = b * b;
    int c_squared = c * c;

    if ((a_squared + b_squared == c_squared) || (a_squared + c_squared == b_squared) || (b_squared + c_squared == a_squared)) {
        printf("Triangle with sides %d, %d, %d is rectangle.\n", a, b, c);
        return 0;
    }

    printf("Triangle with sides %d, %d, %d is NOT rectangle.\n", a, b, c);

    return 0;
}