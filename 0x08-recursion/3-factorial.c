#include "main.h"

/**
 * factorial - function that finds the factorial of an integer
 * @n: the integer
 * Return: -1 if n is less than 0
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
