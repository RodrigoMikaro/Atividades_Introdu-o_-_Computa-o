/*
  $ cat 2ints.txt 
  111 222
  $ ./a.out < 2ints.txt 
  Valor devolvido por scanf: 1
  Valor de x: 111
  Valor devolvido por scanf: 1
  Valor de x: 222
  Valor devolvido por scanf: -1
  Valor de x: 222
  $ 
 */

#include <stdio.h>

int main()
{
    int x;
    printf("Valor devolvido por scanf: %d\n", scanf("%d", &x));
    printf("Valor de x: %d\n", x);

    printf("Valor devolvido por scanf: %d\n", scanf("%d", &x));
    printf("Valor de x: %d\n", x);
    
    printf("Valor devolvido por scanf: %d\n", scanf("%d", &x));
    printf("Valor de x: %d\n", x);
    return 0;
}