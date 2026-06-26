#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int p = atoi(argv[1]);

    if (p <= 1) {
        printf("%d is NOT prime by definition\n", p);
        return 0;
    }

    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            printf("%d is NOT prime because %d divides %d\n", p, i, p);
            return 0;
        }
        else {
            continue;
        }
    }

    printf("%d is prime\n", p);

    return 0;
}