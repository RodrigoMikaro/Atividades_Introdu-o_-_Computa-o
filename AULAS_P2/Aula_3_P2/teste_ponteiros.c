#include <stdio.h>
#include <stdlib.h>

void squared(int *pointer);


int main(void) {

    int a;
    int *pa;

    a = 10;
    pa = &a;

    squared(pa);

    printf("a = %d; endereço de a = %p\n", a, (void *)pa);

    return 0;
}

void squared(int *pointer){
    *pointer *= *pointer;
}

