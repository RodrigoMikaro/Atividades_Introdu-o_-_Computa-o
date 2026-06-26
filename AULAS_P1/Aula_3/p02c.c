/*
  PROBLEMA 2.  Dada uma sequÃªncia de nÃºmeros inteiros, determinar
  quantos nÃºmeros hÃ¡ na sequÃªncia.  Por exemplo, para a sequÃªncia

  12    17   4    -6    8

  seu programa deve imprimir 5.

  $ ./a.out 
  12    17   4    -6    8  (<Enter> seguido de Ctrl D)
  5
  $   
  
 */

#include <stdio.h>

int main() {
    int integers = 0;
    int number;

    

    while (scanf("%d",&number) == 1) {
        integers++;
    }

    printf("Number of integers in the sequence: %d\n", integers);

    return 0;
}






/*
{
    int x, N = 0;

    while (scanf("%d", &x) == 1) 
        N++;

    printf("%d\n", N);

    return 0;
}

*/