#include "main.h"
#include <stdio.h>

/**
 * main - the function that prints its own name
 * @argc: argc parameter
 * @argv: an array of the command listed
 * Return: 0 when successful
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
