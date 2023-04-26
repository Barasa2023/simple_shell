#include "shell.h"

/**
 * _strncpy - copy a string.
 * @dest: destination for copied string.
 * @src: Original string.
 * @n: Number of characters in src string
 * Return: The string copied.
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	if (dest && src && n != 0)
	{
		for (i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}

		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
