/* Problem 2.55:
 * Compile and run the sample code that uses show_bytes (file show-bytes.c) on 
 * different machines to which you have access. Determine the byte orderings used 
 * by these machines.
 *
 * Problem 2.56:
 * Try running the code for show_bytes for different sample values.
 *
 * Problem 2.57:
 * Write procedures show_short, show_long, and show_double that print the byte 
 * representations of C objects of types short, long, and double, respectively.
 * Try these out on several machines.
 */

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_void(void *x);
void show_short(short x);
void show_long(long x);
void show_double(double x);

int main(void)
{
    int x = 420;
    float y = 6.9;
    void *x_ptr = &x;
    void *y_ptr = &y;
    short sh = 0xfff;
    long lng = 11e+11;
    double dbl = 123456789.12345;

    show_int(x);
    show_float(y);
    printf("Void ptr for int: ");
    show_void(x_ptr);
    printf("Void ptr for float: ");
    show_void(y_ptr);

    show_short(sh);
    show_long(lng);
    show_double(dbl);
    return 0;
}


void show_bytes(byte_pointer start, size_t len)
{
    unsigned int i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    printf("int %d bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    printf("float %f bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_void(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x)
{
    printf("short %d bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x)
{
    printf("long %ld bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x)
{
    printf("double %lf bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(double));
}
