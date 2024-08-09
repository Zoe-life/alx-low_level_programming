C
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int   
 n)
{
    int i, max_size;

    if (n == 0)
    {
        _putchar('0');
        return;
    }

    max_size = sizeof(unsigned long int) * 8 - 1;

    for (i = max_size; i >= 0; i--)
    {
        if (n & (1UL << i))
            _putchar('1');
        else
            _putchar('0');
    }
}