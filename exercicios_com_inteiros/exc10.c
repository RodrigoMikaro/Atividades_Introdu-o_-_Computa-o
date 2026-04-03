#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);

    for (int i = 1; i <= n - 3; i++) {
        if (n % i == 0) {
            if (i * (i + 1) * (i + 2) == n) {
                printf("%d is triangular because %d * %d * %d = %d\n", n, i, i + 1, i + 2, n);
                return 0;
            }
        }
    }

    printf("%d is NOT triangular\n", n);

    return 0;
}