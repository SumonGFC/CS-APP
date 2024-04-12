/* Write a C expression that will yield a word consisting of the least
 * significant byte of x and the remaining bytes of y.
 * For operands x = 0x89ABCDEF and y = 0x76543210, this would give 0x765432EF.
 */

#include <stdio.h>

int main(void)
{
    size_t correct = 0x765432EF;
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;
    size_t mask = 0xFF; // least significant byte
    size_t z =  (x & mask) | (y & ~mask);
    printf("%lx\n", z);
    printf("%d\n", z == correct);
    return 0;
}
