#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int a = 1;
    int b = 1;
    int c;

    if (n <= 2) {
        printf("F%d = 1\n", n);
        return 0;
    }

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    printf("F%d = %d\n", n, c);

    return 0;
}
