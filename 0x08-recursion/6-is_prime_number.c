#include "main.h"

/**
 * is_divisible - function that tests whether the number is divisible
 *
 * @n: the number being tested
 * @div: the divisor
 *
 * Description: the function tests whether the number is divisible by 2
 * then returns the value
 * Return: the result
 */

int is_divisible(int n, int div)
{
	if (n % div == 0)
	{
	return (0);
	}
	if (div == n / 2)
	{
		return (1);
	}

	return (is_divisible(n, div + 1));
}


/**
 * is_prime_number - is the integer a prime number
 * @n: the number being tested
 *
 * Description: The function tests whether is a prime number
 * and returns the appropriate value.
 * Return: result
 */
int is_prime_number(int n)
{
	int div = 2;

	if (n <= 1)
	{
		return (0);
	}

	if (n <= 3)
	{
		return (1);
	}

	return (is_divisible(n, div));
}
