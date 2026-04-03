/*
Em caso de empate entre dois alunos (menor ou maior nota), 
o primeiro aluno (n menor) que será registrado.
*/

#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int grade;
    int best_student, highest_grade;
    int worst_student, lowest_grade;

    scanf("%d", &grade);
    highest_grade = grade;
    lowest_grade = grade;
    worst_student = 1;
    best_student = 1;


    for (int i = 2; i <= n; i++) {
        scanf("%d", &grade);
        if (grade < lowest_grade) {
            lowest_grade = grade;
            worst_student = i;
        }
        if (grade > highest_grade) {
            highest_grade = grade;
            best_student = i;
        }
    }

    printf("Best student: %d with grade %d\n", best_student, highest_grade);
    printf("Worst student: %d with grade %d\n", worst_student, lowest_grade);


    return 0;
}