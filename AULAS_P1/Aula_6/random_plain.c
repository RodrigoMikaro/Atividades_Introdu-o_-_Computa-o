/*
  $ ./a.out 8 21662026
  1148934639
  2119007496
  290183424
  177444831
  1607972581
  1260955019
  1502375737
  316290333
  $ 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int seed = atoi(argv[2]);

    srand(seed);
    for (int i = 0; i < N; ++i) {
        int x = rand();
        printf("%d\n", x);
    }
    
    return 0;
}