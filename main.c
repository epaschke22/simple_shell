#include "shell.h"

/**
 * sigint - Prints out the signal
 * @sig: Signal type
 * Return: void
 */

void sigint(int sig)
{
	/* This could be moved to helper functions */
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * runbuiltins - runs built in functions
 * @input: user input
 * @env: environtment for printing
 * @buf: buffer to free if exit
 * Return: status of called builtins or -1 on fail
 */

int runbuiltins(char **input, char **env, char *buf)
{
	int status;
	int c = 0;
	/* Arr of structs containing a string and a function pointers */
	t_blist arr[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};
	/*
	 * Unlikely case but its good to check twice
	 */
	if (input[0] == NULL)
		return (-1);
	if (_strcmp(input[0], "exit"))
	{
		free_double(input);
		free(buf);
		exit(EXIT_SUCCESS);
	}
	while (arr[c].command != NULL)
	{
		if (_strcmp(arr[c].command, input[0]) == 1)
		{
			status = (arr[c].fptr)(env);
			return (status);
		}
		c++;
	}
	/* Did not find the builtin given from input */
	return (-1);
}

/**
 * runprograms - runs the commands based on input tokens
 * @input: input double pointer
 * @env: environment
 * Return: 1 on success, -1 on fail.
 */
int runprograms(char **input, char **env)
{
	/* initializing the usual */
	char **path, *adress, *getpath;
	int i, fd;

	if (env == NULL)
		return (-1);
	/* checks if the first input is a valid program */
	fd = access(input[0], F_OK);
	if (fd == 0)
	{
		execute(input[0], input, env);
		return (1);
	}
	fd = 0;
	getpath = _getenv("PATH", env);
	if (getpath == NULL)
		return (-1);
	path = str_to_double(getpath, ":");
	/* Pretty similar to runbuiltin function */
	for (i = 0; path[i] != NULL; i++)
	{
		adress = catcmd(path[i], input[0]);
		fd = access(adress, F_OK);
		if (fd == 0)
		{
			execute(adress, input, env);
			free(adress);
			free(getpath);
			free_double(path);
			return (1);
		}
		free(adress);
	}
	/* Always freeing stuff after use */
	free(getpath);
	free_double(path);
	return (-1);
}


/**
 * rebuild - rebuils the input buffer and fixes space issues
 * @buf: input string
 * Return: new string called output
 */
char *rebuild(char *buf)
{
	char *output;
	int i;

	output = malloc((_strlen(buf) + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);

	for (i = 0; buf[i]; i++)
	{
		if (buf[i] == '\n' || buf[i] == '#')
			output[i] = '\0';
		else
			output[i] = buf[i];
	}
	output[i] = '\0';
	return (output);
}

/**
 * main - shell project main function
 * @ac: number of arguments
 * @av: list of arguments
 * @env: list of environment cariables
 * Return: 0 on exit, else 1 on failure
 */
int main(int ac, char *av[], char **env)
{
	size_t bufsize;
	char *buffer = NULL, *buf, **input;
	int status = 1, cmd = 0, error = 0, line, count = 0;
	(void)ac;
	/* sigint() is triggered when the processes are interupted */
	signal(SIGINT, sigint);
	while (status)
	{
		count++;
		buffer = NULL;
		bufsize = 0;
		/* This is how Non-Interactive Mode works */
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);
		line = getline(&buffer, &bufsize, stdin);
		if (line == -1)
		{
			status = 0;
			free(buffer);
			continue;
		}
		/* Checks if there are empty spaces before command */
		if (checkempty(buffer))
		{
			free(buffer);
			continue;
		}
		buf = rebuild(buffer);
		input = str_to_double(buf, " ");
		free(buf);
		cmd = runbuiltins(input, env, buffer);
		if (cmd == -1)
			error = runprograms(input, env);
		if (error == -1)
			printerror(av[0], input[0], count);
		free_double(input);
		free(buffer);
	}
	return (0);
}
