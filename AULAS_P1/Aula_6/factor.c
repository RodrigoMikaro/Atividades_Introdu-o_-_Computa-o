/*
  Factors a given number.

  $ ./a.out 2166
  2 3 19 19 
  $ ./a.out 21662166
  2 3 19 19 73 137 
  $ ./a.out 2147483647
  2147483647 
  $   

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int d = 2;

    while (N >= d) {
        if (N % d != 0) {
            d++;
        } else {
            printf("%d ", d);
            N /= d;
        }
    }
    printf("\n");
    return 0;
}