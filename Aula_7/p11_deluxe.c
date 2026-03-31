/*
  Problema 11b.  Dada uma sequÃªncia de nÃºmeros naturais, decidir pada
  cada um deles se o nÃºmero Ã© primo ou nÃ£o.

  $ cat seq.txt 
  36403962
  1956033586
  1376811626
  936701757
  2091297389
  570366474
  $ ./a.out < seq.txt 
  36403962: 2 divides 36403962
  1956033586: 2 divides 1956033586
  1376811626: 2 divides 1376811626
  936701757: 3 divides 936701757
  2091297389: 43 divides 2091297389
  570366474: 2 divides 570366474
  $ ./random_plain 8 20262166 | ./a.out 
  1243807736: 2 divides 1243807736
  1070799054: 2 divides 1070799054
  1006738718: 2 divides 1006738718
  233978713: 37 divides 233978713
  437671734: 2 divides 437671734
  817342363: 817342363 is prime
  1767688729: 1767688729 is prime
  1255695705: 3 divides 1255695705
  $ ./random_plain 100 20262166 | ./a.out | grep prime
  817342363: 817342363 is prime
  1767688729: 1767688729 is prime
  98261753: 98261753 is prime
  929895191: 929895191 is prime
  $
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    int N;
    int passei;

    while (scanf("%d", &N) == 1) {
        if (N <= 1) {
            printf("%d is not a prime\n", N);
            continue;
        }

        for (int d = 2; d < N; d++) {
            if (N % d == 0) {
                printf("%d divides %d\n", d, N);
                passei = 1;
                break;
            }
        }
    
        if (passei == 1) {
            printf("%d is not a prime\n", N);
        }
        else {
            printf("%d is prime\n", N);
        }

    }

    return 0;

}