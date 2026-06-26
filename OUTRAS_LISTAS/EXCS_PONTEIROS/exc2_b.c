#include <stdio.h>
#include <stdlib.h>

void troca(int * i, int * j);

int main(void){
    int a = 1;
    int b = 2;

    troca(&a, &b);

    printf("%d %d\n", a, b);



    return 0;
}


void troca (int *i, int *j) {
   int temp;
   temp = *i;
   *i = *j;
   *j = temp;
}
