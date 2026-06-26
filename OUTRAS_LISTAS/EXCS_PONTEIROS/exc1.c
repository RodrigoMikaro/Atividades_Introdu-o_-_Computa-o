#include <stdio.h>
#include <stdlib.h>

void main() {
   int x, y, *p; y = 0;
   // y = 0
   p = &y;
   // p = endereco de y
   x = *p;
   // x = valor de valor de p = valor de endereco de y = valor de y  0
   // x = 0 | y = 0 | p = &y
   x = 4;
    // x = 4 | y = 0 | p = &y

   (*p)++;

    // x = 4 | y = 1 | p = &y

   --x;
    
   // x = 3 | y = 1 | p = &y

   (*p) += x;

    // x = 3 | y = 4 | p = &y

    printf("%d %d %p\n", x, y, p);
}

//Valores de x, y, e *p ao final do código:
// x = 
// y = 
// * p