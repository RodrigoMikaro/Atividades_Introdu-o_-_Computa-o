/*
  Problema 6 (variante): dada um sequÃªncia de inteiros, determinar o
  maior e o menor elemento na sequÃªncia.  A sequÃªncia deve ser lida da
  entrada padrÃ£o.

  $ cat seq.txt 
  36403962
  1956033586
  1376811626
  936701757
  2091297389
  570366474
  $ ./a.out < seq.txt 
  min: 36403962
  max: 2091297389
  $ random_plain 1000000 2166 | ./a.out 
  min: 373
  max: 2147483064
  $   
 */ 

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int x;
    scanf("%d", &x);
    int min = x;
    int max = x;


    while (scanf("%d", &x) != EOF) {
        
        if (x < min) {
            min = x;
        }
        else {
            max = x;
        }

    }


    printf("máximo: %d\n", max);
    printf("mínimo: %d\n", min);


    return 0;
}