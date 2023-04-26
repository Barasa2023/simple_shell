#include "shell.h"

/**
 * free_mem - Function to free an array of pointers.
 * @aop: array to be freed.
 * @size: Size of the array.
 * Return - void.
*/

void free_mem(char **aop, int size)
{
	int i = 0;

	if (aop && size != 0)
	{
		while (aop[i])
		{
			free(aop[i]);
			i++;
		}

		free(aop);
		return;
	}
	else
	{
		perror("Array or size not received | That pointers are already free.");
		return;
	}
}
