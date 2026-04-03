#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int x = atoi(argv[1]);
    int n = atoi(argv[2]);
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= x;
    }

    printf("X (%d) to the %dth power is equal to %d.\n", x, n, result);

    return 0;
}
