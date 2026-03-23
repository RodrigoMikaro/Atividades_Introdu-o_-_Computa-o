/*
  Problema 11.  Dado um inteiro positivo N, verificar se N Ã© primo.

  O valor de N deve ser lido da linha de comando.

  $ ./a.out 19
  19 is prime
  $ ./a.out 39
  3 divides 39
  $ ./a.out 387829661
  387829661 is prime
  $   
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int N = atoi(argv[1]);

    int d = 2;

    while (d < N) {
        if(N % d == 0) {
            printf("%d")
        }


    }

    return 0;
}