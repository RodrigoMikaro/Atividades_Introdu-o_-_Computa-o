#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int prime;

    for  (int i = 2; i <= n; i++) {

        bool is_prime = true;

        if (n % i == 0) {
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime == true) {
                prime = i;
            }
        }
    }

    printf("%d is the highest prime.\n", prime);
    return 0;
}