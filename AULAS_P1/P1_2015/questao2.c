#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int triangulars = 0;
    int i = 0;
    int j = 0;

    while (triangulars < n) {
        i++;
        j = j + i;
        printf("%d: ", j);
        for (int d = 1; d <= j; d++) {
            if (j % d == 0) {
                printf("%d ", d);
            }
        }
    
        printf("\n");
        triangulars++;

    }

    return 0;
}