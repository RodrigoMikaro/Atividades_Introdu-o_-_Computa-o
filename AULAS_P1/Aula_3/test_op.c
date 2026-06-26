/*
 * $ gcc test_op.c
 * $ ./a.out 11 3
 * 11 % 3 = 2
 * $ 
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d %% %d = %d\n", a, b, a % b);
    return 0;
}