#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int even_sum = 0;
    int integer;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &integer);
        if (integer % 2 == 0) {
            even_sum += integer;
        }
    }

    printf("Even sum = %d\n", even_sum);

    return 0;
}