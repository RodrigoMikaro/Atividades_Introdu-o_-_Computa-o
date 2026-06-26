/*
  Teorema.  Sejam a e b dois inteiros escolhidos independentemente em {1,
  2, ..., M}, de forma uniforme (isto Ã©, sem nenhum viÃ©s).  Vale que a
  probabilidade de a e b serem coprimos tende a ... quando M tende ao
  infinito. 

  Escreva um programa para produzir evidÃªncia experimental consistente
  com o fato acima.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int seed = atoi(argv[2]);
    srand(seed);

    int coprime = 0;
    for (int i = 0; i < N; ++i) {
        int a = rand();
        int b = rand();
        while (a == 0 || b == 0) {
            a = rand();
            b = rand();
        }

        int r = a % b;
        while (r > 0) {
            a = b;
            b = r;
            r = a % b;
        }
        if (b == 1)
            coprime++;
    }

    printf("%lg\n", 1.0 * coprime / N);
    
    return 0;
}