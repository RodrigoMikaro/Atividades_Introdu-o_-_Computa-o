// ------------- [1] BIBLIOTECAS ------------- //

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



// ------------- [1] BIBLIOTECAS ------------- //
  
  #include <stdio.h> 
  #include <stdlib.h>



// ------------- [2] MAIN ------------- //

  int main() {
    
    int numbers = 0;
    int num;

    while (scanf("%d", &num) == 1) {
      numbers++;
    }

    printf("%d\n", numbers);
    return 0;
  }