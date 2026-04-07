#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int n = atoi (argv[1]);

    if (n == 0) {
        printf("Highest length is 0 (zero)\n");
        return 0;
    }

    int current_number;
    int previous_number;
    int highest_length = 0;
    int current_length = 0;

    scanf("%d,", &current_number);
    previous_number = current_number;
    current_length = 1;
    highest_length = current_length;

    for (int i = 2; i <= n; i++) {
        scanf("%d, ", &current_number);
        if (current_number >= previous_number) {
            current_length++;
        }

        else if (current_number < previous_number) {
            current_length = 1;
        }

        if (current_length > highest_length) {
            highest_length = current_length;
        } 
        
        previous_number = current_number;

    }

    printf("Highest length in the list is: %d\n", highest_length);

    return 0;
}