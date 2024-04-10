

#include <stdint.h>
#include <stdio.h>

int main(void)
{
    printf("BASIC TYPES:\n");
    printf("size of size_t: %ld\n", sizeof(size_t));
    printf("size of char: %ld\n", sizeof(char));
    printf("size of short: %ld\n", sizeof(short));
    printf("size of int: %ld\n", sizeof(int));
    printf("size of long: %ld\n", sizeof(long));
    printf("size of int32_t: %ld\n", sizeof(int32_t));
    printf("size of int64_t: %ld\n", sizeof(int64_t));
    printf("size of float: %ld\n", sizeof(float));
    printf("size of double: %ld\n", sizeof(double));


    printf("\nPOINTER TYPES\n");
    printf("size of void *: %ld\n", sizeof(void *));
    printf("size of size_t *: %ld\n", sizeof(size_t *));
    printf("size of char *: %ld\n", sizeof(char *));
    printf("size of short *: %ld\n", sizeof(short *));
    printf("size of int *: %ld\n", sizeof(int *));
    printf("size of long *: %ld\n", sizeof(long *));
    printf("size of int32_t *: %ld\n", sizeof(int32_t *));
    printf("size of int64_t *: %ld\n", sizeof(int64_t *));
    printf("size of float *: %ld\n", sizeof(float *));
    printf("size of double *: %ld\n", sizeof(double *));
    return 0;
}
