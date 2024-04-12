/* Write a procedure is_little_endian that will return 1 when compiled and run
 * on a little-endian machine, and will return 0 when compiled and run on a
 * bigendian machine. This program should run on any machine, regardless of its
 * word size.
 */

#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian();

int main(void)
{
    if (is_little_endian() == 0)
        printf("This machine is little-endian\n");
    else
        printf("This machine is big-endian\n");
    return 0;
}

int is_little_endian()
{
    unsigned short x = 1;
    byte_pointer ptr = (byte_pointer) &x;
    unsigned int i;

    printf("Byte representation of unsigned short x = 1: ");
    for (i = 0; i < sizeof(unsigned short); i++)
        printf("%.2x ", *(ptr + i));
    printf("\n");

    return !(*ptr);
}
