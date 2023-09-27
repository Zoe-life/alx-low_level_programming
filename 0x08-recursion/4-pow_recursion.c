#include "main.h"

/**
 * _pow_recursion - raises an integer to the specified power
 * @x: the integer to be raised
 * @y: the power
 *
 * Return: -1 if y is lower than 0
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	if (y > 0)
	{
		return (x * _pow_recursion(x, y - 1));
	}
	return (1);
}
