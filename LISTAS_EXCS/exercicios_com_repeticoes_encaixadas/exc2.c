#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    bool any_hypotenuse = false;
    bool is_hypotenuse = false;


    for (int h = 1; h <= n; h++) {
        
        is_hypotenuse = false;

        for (int a = 1; a <= h - 1 && is_hypotenuse == false; a++) {
            for (int b = a; b <= h - 1; b++) {
                if (h * h == a * a + b *b) {
                    printf("%d (%d %d)\n", h, a, b);
                    is_hypotenuse = true;
                    any_hypotenuse = true;
                }
            }
        }
    }

    if (any_hypotenuse == false) {
        printf("There is no hypotenuse for %d.\n", n);
    }

    return 0;
}