#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);


    for (int i = 1; i <= 2 * n; i += 2) {
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}
