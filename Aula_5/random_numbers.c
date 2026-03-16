#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    int seed = atoi(argv[2]);

    srand(seed);

    for (int i = 0; i < N; i++) {
        int x = rand();
        printf("%d\n", x);

    }

    return 0;
}