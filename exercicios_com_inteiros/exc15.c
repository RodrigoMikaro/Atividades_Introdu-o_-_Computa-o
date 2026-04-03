// n naturais congruentes a j, ambos em módulo m

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int j = atoi(argv[2]);
    int m = atoi(argv[3]);
    
    int r = 0;
    int s = 0;

    while (r < n) {
        if (s % m == j % m) {
            printf("%d ", s);
            r++;
        }
        s++;
    }

    printf("\n");
    
    return 0;
}