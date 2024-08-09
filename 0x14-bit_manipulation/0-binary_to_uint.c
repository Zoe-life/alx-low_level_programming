#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: The binary string.
 *
 * Return: The converted unsigned int, or 0 if there is an error.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int val = 0;
    int i = 0;

    if (b == NULL)
    {
        return (0);
    }

    while (b[i])
    {
        if (b[i] != '0' && b[i] != '1')
        {
            return (0);
        }

        val <<= 1; /* Left shift val by 1 to make space for the new digit */
        val += (b[i] - '0'); /* Add the current digit (0 or 1) to val */
        i++;
    }

    return (val);
}