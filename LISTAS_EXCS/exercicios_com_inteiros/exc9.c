#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int i = atoi(argv[2]);
    int j = atoi(argv[3]);
    int x = 1;
    int z = 1;

    printf("0");

    while (x < n) {
        z++;
        if (z % i == 0 || z % j == 0) {
            printf(", %d", z);
            x++;
        }
    }

    printf(".\n");

    return 0;
}