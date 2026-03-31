#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    int p = 2;

    while (p <= N){
        if (N % p == 0) {
            N /= p;
            printf("%d ", p);
        }
        else {
            p++;
        }
    }

    printf("\n");

    return 0; 
}