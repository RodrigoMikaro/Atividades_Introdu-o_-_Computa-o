#include <stdio.h>
#include <stdlib.h>

int main(int arg, char *argv[]){
    int n = atoi(argv[1]);
    int f = atoi(argv[2]);

    int lancamentos[n];
    int faces[f];

    for(int i = 0; i < f; i++){
        faces[i] = 0;
    }

    for(int i = 0; i < n; i++){
        scanf(" %d", &lancamentos[i]);
    }

    for(int i = 0; i < f; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 == lancamentos[j]){
                faces[i]++;
            }
        }
    }

    for(int i = 0; i < f; i++){
        printf("Face %d: %d vezes.\n", i + 1, faces[i]);
    }

    return 0;
}