#include "shell.h"

/**
 * printenv - Function to print the current program environment.
 * @envp: Pointers array to env variables
 * Return - void.
 */

void printenv(char **envp)
{
	int i = 0;

	if (envp)
	{
		while (envp[i])
		{
			write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return;
	}
	perror("Unable to find envp.");
}
