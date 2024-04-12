/* Suppose we number the bytes in a w-bit word from 0 (least significant) to
 * w/8 − 1 (most significant). Write code for the following C function, which
 * will return an unsigned value in which byte i of argument x has been
 * replaced by byte b: 
 *      unsigned replace_byte (unsigned x, int i, unsigned char b);
 * Here are some examples showing how the function should work:
 *      replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 *      replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
 */

#include <stdio.h>

unsigned int replace_byte(unsigned int x, int i, unsigned char b);


int main(void)
{
    unsigned int num = 0x12345678;
    unsigned char b = 0xAB;
    int i_1 = 2;
    int i_2 = 0;

    printf("%x\n", replace_byte(num, i_1, b));
    printf("%x\n", replace_byte(num, i_2, b));
    return 0;
}

unsigned int replace_byte(unsigned int x, int i, unsigned char b)
{
    unsigned int x_mask = 0xFF;
    unsigned int b_mask = (unsigned int) b;
    int j;

    i = i % sizeof(unsigned int);
    if (i < 0)
        i = i*(-1);
    
    for (j = 0; j < i; ++j) {
        x_mask = x_mask << 8;
        b_mask = b_mask << 8;
    }

    return (x & (~x_mask)) | b_mask;
}
