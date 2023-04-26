#include "shell.h"

/**
 * _strcat - concatenates two strings
 * Description: Concatenated string
 * @dest: command name
 * @src: command to concatenate.
 * Return: Success
 **/

char *_strcat(char *dest, char *src)
{
	char *s_concat = NULL;
	int lendest = 0, lensrc = 0, i_s = 0, idest = 0;

	if (dest && src)
	{
		lendest = _strlen(dest);
		lensrc = _strlen(src);
		s_concat = malloc(sizeof(char) * (lendest + lensrc + 2));

		if (s_concat)
		{
			while (src[i_s])
			{
				s_concat[i_s] = src[i_s];
				i_s++;
			}

			s_concat[i_s++] = '/';

			while (dest[idest])
			{
				s_concat[i_s] = dest[idest];
				idest++;
				i_s++;
			}

			s_concat[i_s] = '\0';
			return (s_concat);
		}
	}
	perror("_strcat - Unable to find dest and src.");
	return (NULL);
}
