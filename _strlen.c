#include "shell.h"

/**
 * _strlen - Function to find the length of a string.
 * @str: String
 *
 * Return: Then length
*/

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{}

	return (i);
}
