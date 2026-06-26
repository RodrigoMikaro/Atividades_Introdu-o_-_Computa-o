#include <stdio.h>
#include <stdlib.h>

int adicao(int * a, int b);
int multiplicacao(int * a, int b);

int main(void){
    int x = 4;
    int * px = &x;
    int y = *px + 1;

    adicao(&x, 54);

    multiplicacao(&y, 3);

    printf("%d %d\n", x, y);

    return 0;
}

int adicao(int * a, int b){
    *a = *a + b;
}

int multiplicacao(int * a, int b){
    *a = *a * b;
}