#include "main.h"
#include <stdio.h>

/**
 * main - a function that prints its own name
 * @argc: argc parameter
 * @argv: an array of the command listed
 * Return: 0 when successful
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
