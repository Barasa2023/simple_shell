#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


char **mem_alloc(char *, const char *, int len, int *strcount);
int find_exec(char **arguments, char **path, int size0, int size1, int *);
int decision(char **arguments, int size, char **_env, int *wstatus);
int shell_exec(char **aop, const char *path, int size);
void printenv(char **envp);
void free_mem(char **aop, int size);
void find_path(char **aop, int size, char **_env, int *wstatus);


char *_strncpy(char *dest, char *src, int n);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif /* _HEADERS_H_ */
