/*
  PROBLEMA 1.  Dada uma sequÃªncia de nÃºmeros inteiros diferentes de
  zero, terminada por um zero ("sentinela"), imprimir seus quadrados.
  Por exemplo, para a sequÃªncia

  12    17   4    -6    8    0

  seu programa deve imprimir 144 289 16 36 64.  Seu programa deve
  receber a sequÃªncia de nÃºmeros na entrada padrÃ£o.

  $ ./a.out 
  12    17   4    -6    8    0
  144 289 16 36 64 
  $ 

 */

#include <stdio.h>

int main()
{
    int x = 0;

    scanf("%d", &x);

    while (x != 0) {
        printf("%d ", x * x);
        scanf("%d", &x);
    }
    printf("\n");

    return 0;
}
