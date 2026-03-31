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

    int best_to_s_best();
    int update_best();
    int update_s_best();
    int get_best_time();
    int get_s_best_time();
    int print_first_place();
    int print_second_place();



// --------------- VARIÁVEIS GLOBAIS --------------- //

    // Argumentos que serão lidos na entrada padrão:
    // (nº piloto) , (nº tentativa), (tempo da tentativa)
        int pilot, attempt, time = 0;

    // Variáveis armazenando primeiro e segundo melhores:
        int best_pilot = 21;
        int s_best_pilot = 21;
        int best_attempt = 9999999;
        int s_best_attempt = 9999999;
        int best_time = 9999999;
        int s_best_time = 9999999;
    
    // Variáveis de tempo:
        int best_time_min;
        int best_time_sec;
        int best_time_mil;
        int s_best_time_min;
        int s_best_time_sec;
        int s_best_time_mil;



// --------------- MAIN --------------- //
    
    int main(){
        scanf("%d %d %d", &pilot, &attempt, &time);
        best_pilot = pilot;
        best_attempt = attempt;
        best_time = time;

        while (scanf("%d %d %d", &pilot, &attempt, &time) != EOF) {
            
            // Verifica se é o best:
                if (time < best_time) {
                    best_to_s_best();
                    update_best();
                }

                if (time == best_time) {
                    if (pilot != best_pilot) {
                        if (attempt < best_attempt) {
                            best_to_s_best();
                            update_best();
                        }
                        else if (attempt == best_attempt) {
                            if (pilot < best_pilot) {
                                best_to_s_best();
                                update_best();
                            }
                        }
                    }
                }

            // Verifica se é o s_best:
                if (pilot != best_pilot) {
                    if (time < s_best_time) {
                        update_s_best();
                    }
                    else if (time == s_best_time) {
                        if (pilot != s_best_pilot) {
                            if (attempt < s_best_attempt) {
                                update_s_best();
                            }
                            else if (attempt == s_best_attempt) {
                                if (pilot < s_best_pilot) {
                                    update_s_best();
                                }
                            }
                        }
                    }
                }
        }

        get_best_time();
        get_s_best_time();

        print_first_place();
        print_second_place();

        return 0;
    }



// --------------- FUNÇÕES --------------- //


    int best_to_s_best(){
        if (pilot != best_pilot) {
            s_best_pilot = best_pilot;
            s_best_attempt = best_attempt;
            s_best_time = best_time;
        }
        return 0;
    }

    int update_best(){
        best_pilot = pilot;
        best_attempt = attempt;
        best_time = time;
    }

    int update_s_best(){
        s_best_pilot = pilot;
        s_best_attempt = attempt;
        s_best_time = time;
    }

    int get_best_time(){
        best_time_min = best_time / 60000;
        best_time = best_time - best_time_min * 60000;
        best_time_sec = best_time / 1000;
        best_time = best_time - best_time_sec * 1000;
        best_time_mil = best_time;
    }

    int get_s_best_time(){
        s_best_time_min = s_best_time / 60000;
        s_best_time = s_best_time - s_best_time_min * 60000;
        s_best_time_sec = s_best_time / 1000;
        s_best_time = s_best_time - s_best_time_sec * 1000;
        s_best_time_mil = s_best_time;
    }

    int print_first_place(){
        printf("Pole position: Piloto %d", best_pilot);

        if (best_time_min != 1) {
            printf(", com tempo de %d minutos, ", best_time_min);
        }
        else if (best_time == 1) {
            printf(", com tempo de 1 minuto, ");
        }

        if (best_time_sec != 1) {
            printf("%d segundos e", best_time_sec);
        }
        else if (best_time_sec == 1) {
            printf("1 segundo e");
        }

        if (best_time_mil != 1) {
            printf(" %d milissegundos", best_time_mil);
        }
        else if (best_time_mil == 1) {
            printf(" 1 milissegundo");
        }

        printf(" (tentativa %d).\n", best_attempt);
    }

    
    int print_second_place(){
        printf("Segundo lugar: Piloto %d", s_best_pilot);

        if (s_best_time_min != 1) {
            printf(", com tempo de %d minutos, ", s_best_time_min);
        }
        else if (s_best_time == 1) {
            printf(", com tempo de 1 minuto, ");
        }

        if (s_best_time_sec != 1) {
            printf("%d segundos e", s_best_time_sec);
        }
        else if (s_best_time_sec == 1) {
            printf("1 segundo e");
        }

        if (s_best_time_mil != 1) {
            printf(" %d milissegundos", s_best_time_mil);
        }
        else if (s_best_time_mil == 1) {
            printf(" 1 milissegundo");
        }

        printf(" (tentativa %d).\n", s_best_attempt);
    }
