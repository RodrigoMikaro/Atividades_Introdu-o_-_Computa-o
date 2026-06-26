/*
  Computes the product of a sequence of integers given in the standard
  input.

  $ ./a.out 
  1 2 3 4 5
  120
  $ ./a.out 
  2 3 5 7 11 13 17 19
  9699690
  $

 */ 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, p = 1;

    while (scanf("%d", &x) != EOF) 
        p *= x;

    printf("%d\n", p);
    return 0;
}