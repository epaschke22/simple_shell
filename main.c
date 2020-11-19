#include "shell.h"

/**
 * sigint - Prints out the signal
 * @sig: Signal type
 * Return: void
 */
void sigint(int sig)
{
	printf("\n");
	write(STDOUT_FILENO, "$ ", 2);
}


/**
 * runbuiltins - runs built in functions
 * @input: user input
 * Return: always 0
 */
int runbuiltins(char **input)
{
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

	getpath = _getenv("PATH", env);
	path = str_to_double(getpath, ":");
	for (i = 0; path[i] != NULL; i++)
	{
		adress = catcmd(path[i], input[0]);
		fd = access(adress, F_OK);
		if (fd == 0)
		{
			execute(adress, input, NULL);
			return;
		}
	}
	if (path[i] == NULL)
		printf("\nCommand '%s' not found.\n\n", adress);
	free(adress);
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
	char *buffer = NULL, **input;
	int status = 1, line, cmd;
	(void)ac;
	(void)av;

	while (status)
	{
		signal(SIGINT, sigint);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO,"$ ",2);
		line = getline(&buffer,&bufsize,stdin);
		if (line == -1)
		{
			status = 0;
			continue;
		}
		input = str_to_double(buffer, " ");
		cmd = runbuiltins(input);
		if (cmd == -1)
			runprograms(input, env);
		free_double(input);
		buffer = NULL;
		bufsize = 0;
	}
	free(buffer);
	buffer = NULL;
	bufsize = 0;
	return (0);
}
