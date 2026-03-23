/*
 Problema 12.  Dados dois nÃºmeros inteiros positivos, determinar o
 mÃ¡ximo divisor comum entre eles usando o algoritmo de Euclides.

 Os dois nÃºmeros serÃ£o dados na linha de comando.

 $ ./a.out 24 15
 mdc(24, 15) = 3
 $ ./a.out 1392896117 1647079021
 mdc(1392896117, 1647079021) = 1
 $ 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int aa = a, bb = b;
    
    int r = a % b;
    while (r > 0) {
        a = b;
        b = r;
        r = a % b;
    }

    printf("mdc(%d, %d) = %d\n", aa, bb, b);
    
    return 0;
}
