#include "shell.h"

#define UNUSED(x) (void)(x)


/**
 * find_path - find $PATH in the program environment.
 * @aop: arguments of the program tu execute.
 * @size: Size of the arrays.
 * @_env: Current environment.
 * @wstatus: Return status of the last program executed.
 * Return - void.
 */

void find_path(char **aop, int size, char **_env, int *wstatus)
{
	char **path = NULL, temp[3000];
	char match[6] = "PATH=";
	int i = 0, ienv = 0, strcount = 0, len = 0, result = 0;

	UNUSED(result);

	while (*_env)
	{
		if (_env[ienv])
		{
			_strncpy(temp, _env[ienv], 1);
			ienv++;
		}

		while (temp[i] == match[i])
		{
			i++;
		}

		if (i == 5)
		{
			len = _strlen(temp);
			path = mem_alloc(temp, "PATH=:\n", len, &strcount);
			result = find_exec(aop, path, size, strcount, wstatus);
			*wstatus = result;
			free_mem(path, strcount);
			return;
		}
	}
}
