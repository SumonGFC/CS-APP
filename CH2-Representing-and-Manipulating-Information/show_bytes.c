#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_void(void *x);

int main(void)
{
    int x = 420;
    float y = 6.9;
    void *x_ptr = &x;
    void *y_ptr = &y;

    show_int(x);
    show_float(y);
    printf("  Void ptr for int: ");
    show_void(x_ptr);
    printf("  Void ptr for float: ");
    show_void(y_ptr);

    return 0;
}


void show_bytes(byte_pointer start, size_t len)
{
    unsigned int i;
    for (i = 0; i < len; i++)
        printf("  %.2x", start[i]);
    printf("\n");
}

/* In the 3 procedures below, show_bytes is passed the address of the procedures
 * arguments, and casts the address to a pointer to unsigned char. This
 * indicates to the compiler that the program should consider the pointer to be
 * a stream of bytes rather than to an object of the original data type
 */

void show_int(int x)
{
    // So here, initially &x points to an int. When we cast it to byte_pointer,
    // the pointer now points to a single byte (unsigned char), which means we
    // can increment this pointer sizeof(int) number of times and print each
    // individual byte contained in x.
    printf("  int %d bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    printf("  float %f bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_void(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}
