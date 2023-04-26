#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define UNUSED(x) (void)(x)

/**
 * main - The entry point for the program
 * Description: execute commands defined of the $PATH.
 * @argc: unused variable.
 * @argv: Unused variable
 * @envp: environment for current executing command
 * Return: (EXIT_SUCCESS)
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL, **aop, *_exit = "exit";
	size_t len = 0;
	ssize_t read_count;
	int scount = 0, w_status = 0;

	signal(SIGINT, SIG_IGN);
	UNUSED(argc);
	UNUSED(argv);

	write(1, "Watcher$ ", 9);
	while ((read_count = getline(&line, &len, stdin)) != EOF)
	{
		if (line && (_strcmp(line, _exit)) != 0)
		{
			scount = 0;
			aop = mem_alloc(line, " \t\r\n\f\v", read_count, &scount);
			if (aop[0] != NULL)
			{
				decision(aop, scount, envp, &w_status);
				free_mem(aop, scount);
			}
			else
				free(aop);

			write(1, "\nWatcher$ ", 10);
		}
		else if ((_strcmp(line, _exit)) == 0)
		{
			free(line);
			exit(w_status);
		}
		else
		{
			perror("Error, unable to allocate buffer\n");
		}
	}

	free(line);
	exit(EXIT_SUCCESS);

}
