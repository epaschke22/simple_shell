#include "shell.h"


/**
 * sigint - Prints out the signal
 * @sig: Signal type
 * Return: void
 */
void sigint(int sig)
{
	printf("\n");
}
/**
 * runcomands - runs the commands based on input tokens
 * @input: input double pointer
 * @env: environment
 * Return: void
 */
void runcomands(char **input, char **env)
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
			/* Executes the command if found */
			if (execve(adress, input, NULL) == -1)
			{
				printf("Execve Error\n");
				exit(0);
			}
			break;
		}
	}
	if (path[i] == NULL)
		printf("Command '%s' not found.\n", adress);
		/*printf("Error Number : %d\n", fd);*/
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
	char *buffer = NULL, **input, **tmpenv;
	int status = 1;
	(void)ac;
	(void)av;

	/*signal(SIGINT, SIG_IGN)*/
	while (status)
	{
		tmpenv = env;
		write(STDOUT_FILENO,"$ ",2);
		signal(SIGINT, sigint);
		getline(&buffer,&bufsize,stdin);
		input = str_to_double(buffer, " ");
		runcomands(input, env);
		free_double(input);
		buffer = NULL;
		bufsize = 0;
	}
	return(0);
}
