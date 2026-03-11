/*

  Este programa ilustra o fato que scanf() devolve um valor: o nÃºmero
  de "leituras" bem sucedidas.

  $ ./a.out
  1 2 3
  s = 3
  $ ./a.out
  1 2 x
  s = 2
  $ ./a.out
  x 1 2
  s = 0
  $ 
  
 */

#include <stdio.h>

int main()
{
    int s, x0, x1, x2;

    s = scanf("%d %d %d", &x0, &x1, &x2);

    printf("s = %d\n", s);

    return 0;
}