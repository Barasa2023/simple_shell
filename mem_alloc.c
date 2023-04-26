#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * mem_alloc - Function to create a dynamic array of pointers
 * @string: The original string.
 * @delim: The delimiter characters for strtok() function.
 * @len: Length of the entire (string).
 * @strcount: Variable to store tokens
 * Return: Success.
 */

char **mem_alloc(char *string, const char *delim, int len, int *strcount)
{
	char *temp, *token, **aop;
	int i = 0, stlen[120];

	temp  = malloc(sizeof(char) * (len + 1));
	if (temp)
	{
		temp = _strncpy(temp, string, len);
		token = strtok(temp, delim);

		while (token != NULL)
		{
			stlen[i] = _strlen(token);
			token = strtok(NULL, delim);
			(*strcount)++;
			i++;
		}
		free(temp);
	}
	else
		perror("Buffer not found. (Malloc)");
	aop = malloc(sizeof(*aop) * (*strcount + 1));
	for (i = 0; i < (*strcount); i++)
		aop[i] = malloc(sizeof(char) * (stlen[i] + 1));
	aop[(*strcount)] = NULL;
	if (aop)
	{
		i = 0;
		temp = strtok(string, delim);
		aop[i] = _strncpy(aop[i], temp, (stlen[0] + 1));
		temp = strtok(NULL, delim);
		while (aop[i] && temp)
		{
			i++;
			aop[i] = _strncpy(aop[i], temp, (stlen[i] + 1));
			temp = strtok(NULL, delim);
		}
		return (aop);
	}
	return (NULL);
}
