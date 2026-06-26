#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int x[n];
    int y[n];
    double product = 0;

    for(int i = 0; i < n; i++){
        scanf(" %d", &x[i]);
    }

    for(int i = 0; i < n; i++){
        scanf(" %d", &y[i]);
    }

    for(int i = 0; i < n; i++){
        product += x[i] * y[i];
    }

    printf("Produto = %lg.\n", product);

    return 0;
}