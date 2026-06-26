/*
 * $ gcc hello_nomeN.c 
 * $ ./a.out 5 Carlos
 * Hello, Carlos!
 * Hello, Carlos!
 * Hello, Carlos!
 * Hello, Carlos!
 * Hello, Carlos!
 * $ 
 */

#include <stdio.h>  // standard input, output library
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
  int N = atoi(argv[1]);

  while (N > 0) {
    printf("Hello, %s!\n", argv[2]);
    N--;
  }
  
  return 0;
}