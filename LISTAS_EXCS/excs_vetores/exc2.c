#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    char gabarito[30];
    char aluno[30];
    int nota = 0;

    for(int i = 0; i < 30; i++){
        scanf(" %c", &gabarito[i]);
    }

    for(int i = 1; i <= n; i++){
        nota = 0;

        for(int j = 0; j < 30; j++){
            scanf(" %c", &aluno[j]);
            if(aluno[j] == gabarito[j]){
                nota++;
            }
        }

        printf("Aluno %d: %d\n", i, nota);
    }


    return 0;
}