#include "main.h"

/**
 * _strstr - function that locates a substring.
 * @haystack: ensures the initial string is scanned
 * @needle: the string to be searched in the first one
 *
 * Return: this is the pointer to the first occurence of the given string
 */


char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (needle[0] == '\0')
	{
		return (haystack);
	}

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					break;
				}
			}

			if (needle[j] == '\0')
			{
				return (haystack + i);
			}
		}
	}
	return ('\0');
}
