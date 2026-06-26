#include <stdio.h>
#include <stdlib.h>


int main(int arg, char *argv[]){
    int n = atoi(argv[1]);
    int element = 0;
    int sequence[n];

    for(int i = 0; i <= n - 1; i++){
        scanf("%d", &element);
        sequence[i] = element;
    }

    for(int i = n - 1; i >= 0; i--){
        printf("%d ", sequence[i]);
    }

    printf("\n");

    return 0;
}