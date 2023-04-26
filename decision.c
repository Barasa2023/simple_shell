#include "shell.h"

/**
 * decision - Function to execute commands
 * @arguments: Pointers array with the values entered
 * @size: Size of pointers array.
 * @_env: Have the environment from where is executed the program.
 * - env will be pased as an argument of path_finder()
 * @w_status: Return status of previous program.
 * Return: (0) Success.
  **/

int decision(char **arguments, int size, char **_env, int *w_status)
{
	char *com_env = "env";
	int i = 0;

	if (arguments && _env && size != 0)
	{
		if ((**arguments == '/') | (**arguments == '.'))
		{
			i = shell_exec(arguments, arguments[0], size);
			*w_status = i;
			return (*w_status);
		}
		else
		{
			if ((_strcmp(arguments[0], com_env)) == 0)
			{
				printenv(_env);
				return (0);
			}
			else
			{
				find_path(arguments, size, _env, w_status);
				return (0);
			}
		}
	}
	perror("Unable to find arguments, size or arguments.");
	return (-1);
}
