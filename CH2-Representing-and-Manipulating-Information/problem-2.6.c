/* Given a binary representation of an int and a float, shift them relative to
 * eachother until the the number if bits is maximized between them.
 */

#include <stdio.h>
#define MAXLEN 33

void permute_str(char*);
int count_same_bits(char *arr, char *arr2, size_t size);

int main(void)
{
    char int_bin_rep[MAXLEN] = "00000000001001111100100011111000";
    //correct permutation    = "00010010100001111100100011111000"; //shifted right 2 times 
    char float_bin_rep[MAXLEN] = "01001010000111110010001111100000";
    int perm_counts[MAXLEN] = {0};
    int i;

    for (i = 0; i < MAXLEN - 1; ++i) {
        perm_counts[i] += count_same_bits(int_bin_rep, float_bin_rep, MAXLEN);
        printf("%d: %d\n", i, perm_counts[i]);
        permute_str(float_bin_rep);
    }
    printf("%s\n", float_bin_rep);
    return 0;
}

void permute_str(char *arr) {
    // left shift permutation
    char tmp = *arr;

    int i;
    for (i = 0; i <  MAXLEN - 2; ++i) {
        *(arr + i) = *(arr + i + 1);
    }

    *(arr + MAXLEN - 2) = tmp;
}

int count_same_bits(char *arr1, char *arr2, size_t size)
{
    int count = 0;
    unsigned int i;

    for (i = 0; i < size - 2; ++i) {
        if (*(arr1 + i) == *(arr2 + i))
            count++;
    }

    return count;
}
