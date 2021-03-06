#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * struct blist - Struct for pointer functions
 *
 * @command: The command
 * @fptr: Function pointer to a function
 */

typedef struct blist
{
	char *command;
	int (*fptr)(char **dptr);
} t_blist;

/* StrFunctions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *dest, char *src);

/* Helper 1 Functions */
void free_double(char **dptr);
char **str_to_double(char *input, char *delm);
char *catcmd(char *path, char *cmd);
char *_getenv(char *section, char **envir);
void sigint(int sig);
void execute(char *adress, char **input, char **env);

/* Built in Functions */
int shell_exit(char **env);
int shell_env(char **env);

/* Helper Functions */
void printerror(char *av, char *cmd, int count);
int checkempty(char *input);

#endif
