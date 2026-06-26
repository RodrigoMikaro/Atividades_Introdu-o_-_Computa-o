#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// devolve o último dia do mês m, do ano y:
int last_day(int month, int year);

bool is_leap_year(int year);


int main(int argc, char *argv[]) {

    int day = atoi(argv[1]);
    int month = atoi(argv[2]);
    int year = atoi(argv[3]);

    int last_d = last_day(month, year);

    if (day != last_d) {
        day++;
        printf("Next day: %d / %d / %d\n", day, month, year);
    }

    else {
        if (month < 12) {
            day = 1;
            month++;
            printf("Next day: %d / %d / %d\n", day, month, year);
        }

        else {
            day = 1;
            month = 1;
            year++;
            printf("Next day: %d / %d / %d\n", day, month, year);
        }
    }


    return 0;
}

int last_day(int month, int year) {

    int last_d;

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        last_d = 31; 
    }

    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        last_d = 30;
    }

    else if (month == 2) {
        if (is_leap_year (year)) {
            last_d = 29;
        }
        else {
            last_d = 28;
        }
    }

    return last_d;
}

bool is_leap_year(int year){

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    }
    
    return false;
}