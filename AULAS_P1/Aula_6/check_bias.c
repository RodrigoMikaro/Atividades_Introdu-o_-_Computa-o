/*
  Este programa (check_bias.c) recebe dois nÃºmeros naturais na linha
  de comando, T e M, e lÃª uma sequÃªncia nÃ£o vazia de nÃºmeros naturais
  x_0, x_1, ... da entrada padrÃ£o.  A saÃ­da consiste no nÃºmero total
  de x_i lidos, digamos N, e no nÃºmero dos x_i lidos que sÃ£o menores
  que T, digamos s.

  Supondo que os x_i satisfazem 0 <= x_i < M e que eles sÃ£o
  aleatÃ³rios, espera-se que s / N seja por volta de T / M.

  Exemplo.  Lembre que random_plain.c gera nÃºmeros aleatÃ³rios no
  conjunto 0, 1, ..., RAND_MAX = 2^{31} - 1 = 2147483647.  As
  seguintes execuÃ§Ãµes combinadas de random_plain e check_bias ilustram
  a discussÃ£o acima:

  $ random_plain 1000 21662026 | check_bias 1000000000 2147483647
  Smaller than 1000000000: 435
  Total: 1000
  Ratio: 435 / 1000 = 0.435
  Expected: 1000000000 / 2147483647 = 0.465661
  $ random_plain 1000000 21662026 | check_bias 1000000000 2147483647
  Smaller than 1000000000: 466079
  Total: 1000000
  Ratio: 466079 / 1000000 = 0.466079
  Expected: 1000000000 / 2147483647 = 0.465661
  $ random_plain 100000000 21662026 | check_bias 1000000000 2147483647
  Smaller than 1000000000: 46568349
  Total: 100000000
  Ratio: 46568349 / 100000000 = 0.465683
  Expected: 1000000000 / 2147483647 = 0.465661
  $ random_plain 100000000 21669999 | check_bias 1000000000 2147483647
  Smaller than 1000000000: 46562975
  Total: 100000000
  Ratio: 46562975 / 100000000 = 0.46563
  Expected: 1000000000 / 2147483647 = 0.465661
  $

  Comentamos que random_seq_mod.c pode gerar nÃºmeros aleatÃ³rios
  enviesados, e que o viÃ©s pode ser significativo se M for grande.
  Experimente executar random_seq_mod.c e check_bias.c da seguinte
  forma:

  $ random_seq_mod 10000000 1431655765 3123234441 | check_bias 715827882 1431655765

  Por outro lado, experimente executar

  $ random_seq 10000000 1431655765 3123234441 | check_bias 715827882 1431655765

  O programa random_seq.c parece melhor que random_seq_mod.c?
  
  ObservaÃ§Ã£o.  Na realidade, o algoritmo em random_seq.c tambÃ©m gera
  inteiros com viÃ©s se M for grande, mas Ã© um pouco mais difÃ­cil
  identificar o viÃ©s explicitamente.

  Para evitar viÃ©s, vocÃª pode usar random_seq_deluxe.c.
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int T = atoi(argv[1]);
    int M = atoi(argv[2]);
    int s = 0, N = 0;
    int x;
    
    while (scanf("%d", &x) != EOF) {
        N++;
        if (x < T)
            s++;
    }

    printf("Smaller than %d: %d\n", T, s);
    printf("Total: %d\n", N);
    printf("Ratio: %d / %d = %lg\n", s, N, 1.0 * s / N);
    printf("Expected: %d / %d = %lg\n", T, M, 1.0 * T / M);
    
    return 0;
}