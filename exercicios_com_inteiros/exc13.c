#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int sum = 0;

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (sum == n) {
        printf("%d is perfect.\n", n);
        return 0;
    }

    printf("%d is NOT perfect, because %d != %d.\n", n, sum, n);

    return 0;
}
