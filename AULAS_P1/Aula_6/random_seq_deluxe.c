/*

  Given integers N, M and seed, produces N random integers in [0, M).
  Uses seed as the seed of the random number generator.

  $ random_seq_deluxe 10 2 314
  0 1 1 0 1 0 0 1 1 1 
  $ random_seq_deluxe 16 20 314
  18 19 3 4 11 12 18 1 11 15 0 9 8 18 6 0 
  $
  
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int seed = atoi(argv[3]);

    // largest multiple of M < 2^{31}
    int MM = (2147483647 / M) * M;
    
    srand(seed);
    for (int i = 0; i < N; ++i) {
        int x = rand();
        while (x >= MM) 
            x = rand();
        printf("%d ", x % M);  
    }
    printf("\n");

    return 0;
}