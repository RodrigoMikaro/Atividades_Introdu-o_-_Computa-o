/*

  Given integers N, M and seed, produces N random integers in [0, M).
  Uses seed as the seed of the random number generator.

  $ random_seq 10 2 314
  0 0 0 0 0 1 1 0 0 0 
  $ random_seq 16 20 314
  0 6 5 0 5 15 15 3 5 9 8 1 18 17 15 6 
  $ 
  
*/

// --------------------------------------------------- RESOLUÇÃO --------------------------------------------------- //

// ------ [0] BIBLIOTECAS ------ //
    
    #include <stdio.h>  // para usar printf
    #include <stdlib.h> // para usar função rand() e atoi



// ------ [0] Leitura de N argumentos (argv) e array de strings em argv[] ------ //

    int main(int argc, char* argv[]) {

        int N = atoi(argv[1]);
        int M = atoi(argv[2]);
        int seed = atoi(argv[3]);  

        srand(seed);

        for (int i = 0; i < N; i++) {
            int random_number = (rand() % (M + 1));
            printf("%d ", random_number);
        }

        printf("\n");

        return 0;
    }