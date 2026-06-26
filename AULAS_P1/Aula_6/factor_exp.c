/*
  Factors a given number.

  $ ./a.out 2166
  2 3 19(2) 
  $ ./a.out 21662166
  2 3 19(2) 73 137 
  $ ./a.out 945393750
  2 3(2) 5(5) 7(5) 
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
            int e = 1;
            printf("%d", d);
            N /= d;
            while (N % d == 0) {
                N /= d;
                e++;
            }
            if (e == 1) {
                printf(" ");
            } else {
                printf("(%d) ", e);
            }
        }
    }
    printf("\n");
    return 0;
}