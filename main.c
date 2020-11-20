#include "shell.h"

/**
 * sigint - Prints out the signal
 * @sig: Signal type
 * Return: void
 */
void sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * runbuiltins - runs built in functions
 * @input: user input
 * Return: always 0
 */
int runbuiltins(char **input)
{
	int status;
	int c = 0;

	if (input[0] == NULL)
		return (-1);

	blist arr[] = {
		{"exit", shell_exit},
		{NULL, NULL}
	};
	while (arr[c].command != NULL)
	{
		if (_strcmp(arr[c].command, input[0]) == 1)
		{
			status = (arr[c].fptr)();
			return (status);
		}
		c++;
	}
	return (-1);
}

/**
 * runcomands - runs the commands based on input tokens
 * @input: input double pointer
 * @env: environment
 * Return: void
 */
void runprograms(char **input, char **env)
{
	char **path, *adress, *getpath;
	int i, fd;

	fd = access(input[0], F_OK);
	if (fd == 0)
	{
		execute(input[0], input, env);
		return;
	}
	fd = 0;
	getpath = _getenv("PATH", env);
	path = str_to_double(getpath, ":");
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
			return;
		}
		free(adress);
	}
	if (path[i] == NULL)
		perror("Error: ");
	free(getpath);
	free_double(path);
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
	size_t bufsize = 0;
	char *buffer = NULL, *buf, **input;
	int status = 1, cmd, line, i;
	(void)ac;
	(void)av;

	signal(SIGINT, sigint);
	while (status)
	{
		buffer = NULL;
		bufsize = 0;
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "$ ", 2);
		line = getline(&buffer, &bufsize, stdin);
		if (line == -1)
		{
			status = 0;
			free(buffer);
			continue;
		}
		if (buffer[0] == '\n' || buffer[0] == ' ')
		{
			free(buffer);
			continue;
		}
		buf = _strdup(buf, buffer);
		for (i = 0; buf[i]; i++)
			if (buf[i] == '\n')
				buf[i] = '\0';
		input = str_to_double(buf, " ");
		free(buf);
		cmd = runbuiltins(input);
		if (cmd == -1)
			runprograms(input, env);
		free_double(input);
		free(buffer);
	}
	return (0);
}
