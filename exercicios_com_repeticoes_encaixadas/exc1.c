#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);


    for (int i = 1; i <= n; i++) {
        
        int integer = 1;
        int even_sum = 0;

        while (integer != 0) {
            scanf("%d", &integer);

            if (integer % 2 == 0) {
                even_sum += integer;
            }
        }

        printf("Even sum for sequence %d: %d\n", i, even_sum);
    }

    return 0;
}