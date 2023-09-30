#include "main.h"
#include <stdio.h>

/**
 * main - this is a function that prints its name
 * @argc: argc parameter
 * @argv: an array of the command listed
 * Return: 0 when successful
 */


int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
