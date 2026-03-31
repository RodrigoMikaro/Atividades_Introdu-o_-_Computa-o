/******************************************************************************
 Ao preencher esse cabeçalho com o meu nome e o meu número USP, declaro que sou
 o único autor e responsável por esse programa. Todas as partes originais desse
 Exercício-Programa (EP) foram desenvolvidas e implementadas por mim seguindo
 as instruções desse EP e que portanto não constituem desonestidade acadêmica
 ou plágio.

 Declaro também que sou responsável por todas as cópias desse programa e que eu
 não distribuí ou facilitei a sua distribuição. Estou ciente que os casos de
 plágio e desonestidade acadêmica serão tratados segundo os critérios
 divulgados na página da disciplina.

 Entendo que EPs sem assinatura não serão corrigidos e, ainda assim, poderão
 ser punidos por desonestidade acadêmica.

 Nome : Rodrigo Francisco Pettinati Mikaro
 NUSP : 16899844
 Turma: 01
 Prof.: Yoshiharu
******************************************************************************/



// --------------- BIBLIOTECAS --------------- //

    #include <stdio.h>
    #include <stdlib.h>



// --------------- PROTÓTIPOS --------------- //

    int update_best_time(int pilot, int attempt, int attempt_time);

    int update_podium() 


// --------------- VARIÁVEIS GLOBAIS --------------- //

    // Argumentos que serão lidos na entrada padrão:
    // (nº piloto) , (nº tentativa), (tempo da tentativa)
        int pilot, attempt, attempt_time = 0;

    // Melhores tempos de cada piloto:
        int best_1, best_2, best_3, best_4, best_5, best_6, best_7, best_8, best_9, best_10 = 100000000;
        int best_11, best_12, best_13, best_14, best_15, best_16, best_17, best_18, best_19, best_20 = 100000000;

    // Tentativa na qual cada piloto teve seu melhor tempo:
        int attempt_1, attempt_2, attempt_3, attempt_4, attempt_5, attempt_6, attempt_7, attempt_8, attempt_9, attempt_10;
        int attempt_11, attempt_12, attempt_13, attempt_14, attempt_15, attempt_16, attempt_17, attempt_18, attempt_19, attempt_20;

        int best_time, best_attempt, best_pilot;
        int second_best_time, second_best_pilot;



// --------------- MAIN --------------- //
    
    int main() {
        scanf("%d %d %d", &pilot, &attempt, &attempt_time);
        best_pilot
        best_time = 
        best_attempt
        

        while (scanf("%d %d %d", &pilot, &attempt, &attempt_time) != EOF) {
            update_best_time(pilot, attempt, attempt_time);
        }

        printf("")
        return 0;
    }



// --------------- FUNÇÕES --------------- //

    int update_best_time(int pilot, int attempt, int attempt_time) {
        
        if (pilot == 1) {
            if (attempt == 1) {
                best_1 = attempt_time;
                attempt_1 = 1;
            }
            else if (attempt_time < best_1) {
                best_1 = attempt_time;
                attempt_1 = attempt;
            }
        }

        if (pilot == 2) {
            if (attempt == 1) {
                best_2 = attempt_time;
                attempt_2 = 1;
            }
            else if (attempt_time < best_2) {
                best_2 = attempt_time;
                attempt_2 = attempt;
            }
        }

        if (pilot == 3) {
            if (attempt == 1) {
                best_3 = attempt_time;
                attempt_3 = 1;
            }
            else if (attempt_time < best_3) {
                best_3 = attempt_time;
                attempt_3 = attempt;
            }
        }

        if (pilot == 4) {
            if (attempt == 1) {
                best_4 = attempt_time;
                attempt_4 = 1;
            }
            else if (attempt_time < best_4) {
                best_4 = attempt_time;
                attempt_4 = attempt;
            }
        }

        if (pilot == 5) {
            if (attempt == 1) {
                best_5 = attempt_time;
                attempt_5 = 1;
            }
            else if (attempt_time < best_5) {
                best_5 = attempt_time;
                attempt_5 = attempt;
            }
        }

        if (pilot == 6) {
            if (attempt == 1) {
                best_6 = attempt_time;
                attempt_6 = 1;
            }
            else if (attempt_time < best_6) {
                best_6 = attempt_time;
                attempt_6 = attempt;
            }
        }

        if (pilot == 7) {
            if (attempt == 1) {
                best_7 = attempt_time;
                attempt_7 = 1;
            }
            else if (attempt_time < best_7) {
                best_7 = attempt_time;
                attempt_7 = attempt;
            }
        }
    
        if (pilot == 8) {
            if (attempt == 1) {
                best_8 = attempt_time;
                attempt_8 = 1;
            }
            else if (attempt_time < best_8) {
                best_8 = attempt_time;
                attempt_8 = attempt;
            }
        }

        if (pilot == 9) {
            if (attempt == 1) {
                best_9 = attempt_time;
                attempt_9 = 1;
            }
            else if (attempt_time < best_9) {
                best_9 = attempt_time;
                attempt_9 = attempt;
            }
        }

        if (pilot == 10) {
            if (attempt == 1) {
                best_10 = attempt_time;
                attempt_10 = 1;
            }
            else if (attempt_time < best_10) {
                best_10 = attempt_time;
                attempt_10 = attempt;
            }
        }

        if (pilot == 11) {
            if (attempt == 1) {
                best_11 = attempt_time;
                attempt_11 = 1;
            }
            else if (attempt_time < best_11) {
                best_11 = attempt_time;
                attempt_11 = attempt;
            }
        }

        if (pilot == 12) {
            if (attempt == 1) {
                best_12 = attempt_time;
                attempt_12 = 1;
            }
            else if (attempt_time < best_12) {
                best_12 = attempt_time;
                attempt_12 = attempt;
            }
        }

        if (pilot == 13) {
            if (attempt == 1) {
                best_13 = attempt_time;
                attempt_13 = 1;
            }
            else if (attempt_time < best_13) {
                best_13 = attempt_time;
                attempt_13 = attempt;
            }
        }

        if (pilot == 14) {
            if (attempt == 1) {
                best_14 = attempt_time;
                attempt_14 = 1;
            }
            else if (attempt_time < best_14) {
                best_14 = attempt_time;
                attempt_14 = attempt;
            }
        }

        if (pilot == 15) {
            if (attempt == 1) {
                best_15 = attempt_time;
                attempt_15 = 1;
            }
            else if (attempt_time < best_15) {
                best_15 = attempt_time;
                attempt_15 = attempt;
            }
        }

        if (pilot == 16) {
            if (attempt == 1) {
                best_16 = attempt_time;
                attempt_16 = 1;
            }
            else if (attempt_time < best_16) {
                best_16 = attempt_time;
                attempt_16 = attempt;
            }
        }

        if (pilot == 17) {
            if (attempt == 1) {
                best_17 = attempt_time;
                attempt_17 = 1;
            }
            else if (attempt_time < best_17) {
                best_17 = attempt_time;
                attempt_17 = attempt;
            }
        }
    
        if (pilot == 18) {
            if (attempt == 1) {
                best_18 = attempt_time;
                attempt_18 = 1;
            }
            else if (attempt_time < best_18) {
                best_18 = attempt_time;
                attempt_18 = attempt;
            }
        }

        if (pilot == 19) {
            if (attempt == 1) {
                best_19 = attempt_time;
                attempt_19 = 1;
            }
            else if (attempt_time < best_19) {
                best_19 = attempt_time;
                attempt_19 = attempt;
            }
        }

        if (pilot == 20) {
            if (attempt == 1) {
                best_20 = attempt_time;
                attempt_20 = 1;
            }
            else if (attempt_time < best_20) {
                best_20 = attempt_time;
                attempt_20 = attempt;
            }
        }

    best_time = attempt_time

    }

