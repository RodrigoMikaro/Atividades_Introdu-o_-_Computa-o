#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);
    double Harmonic = 0;


    for (int k = 1; k <= n; k++) {
        Harmonic += 1.0/k;
    }

    printf("Hn = %lg, para n = %d\n", Harmonic, n);

    return 0;
}