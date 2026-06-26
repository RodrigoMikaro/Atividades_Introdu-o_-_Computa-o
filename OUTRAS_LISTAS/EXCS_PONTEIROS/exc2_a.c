#include <stdio.h>
#include <stdlib.h>

void main() {
   int x, *p;
   x = 100;
   p = *x;
   // Erro: p = x;
   printf("x = %d | p = %p", x, p);
}