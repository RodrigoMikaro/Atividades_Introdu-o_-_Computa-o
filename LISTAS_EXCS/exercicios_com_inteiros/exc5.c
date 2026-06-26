#include <stdio.h>
#include <stdlib.h>

int main() {

    int highest_day, highest_sales;

    int day, sales;

    scanf("%d %d", &day, &sales);

    highest_day = day;
    highest_sales = sales;

    while (scanf("%d %d", &day, &sales) == 2) {
        if (sales > highest_sales) {
            highest_day = day;
            highest_sales = sales;
        }
        else {
            continue;
        }
    }

    printf("Highest sales at day %d were %d\n", highest_day, highest_sales);

    return 0;
}