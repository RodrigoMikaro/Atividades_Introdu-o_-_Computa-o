#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int factorial = 1;

    if (n == 0) {
        printf("0! = 1\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("%d! = %d\n", n, factorial);


    return 0;
}