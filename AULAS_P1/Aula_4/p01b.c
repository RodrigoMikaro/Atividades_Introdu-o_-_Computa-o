// ------------- [0] ENUNCIADO DO PROBLEMA ------------- //

/*
  PROBLEMA 1.  Dado N e uma sequÃªncia de N nÃºmeros inteiros, imprimir
  seus quadrados.  Por exemplo, se N = 5 e Ã© dada sequÃªncia

  12    17   4    -6    8

  seu programa deve imprimir 144 289 16 36 64.  Seu programa deve
  receber N na linha de comando e a sequÃªncia de nÃºmeros na entrada
  padrÃ£o.

  $ ./a.out 5
  12    17   4    -6    8
  144 289 16 36 64 
  $ 

 */



// ------------- [1] BIBLIOTECAS ------------- //

  #include <stdio.h>
  #include <stdlib.h>


  
// ------------- [2] MAIN ------------- //

  int main(int argc, char* argv[]) {
    
    int N = atoi(argv[1]);

    int number;

    for (int i = 0; i < N; i++) {
      scanf("%d", &number);
      printf("%d ", number * number);
    }

    printf("\n");

    return 0;
  }