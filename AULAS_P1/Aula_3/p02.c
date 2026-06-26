/*
  PROBLEMA 2.  Dada uma sequÃªncia de nÃºmeros inteiros diferentes 
  de zero, terminada por um zero ("sentinela"), determinar 
  quantos nÃºmeros hÃ¡ na sequÃªncia.  Por exemplo, para a sequÃªncia 

  12    17   4    -6    8    0

  seu programa deve imprimir 5.

  $ ./a.out
  12    17   4    -6    8    0
  5
  $

 */

#include <stdio.h>

int main() {

  int x;

  int N = 0;

  scanf("%d", &x);

  while (x != 0) {
    N++;
    scanf("%d", &x);
  }

  printf("%d\n", N);

  return 0;
}