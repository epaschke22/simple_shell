#include "shell.h"

/**
 * execute - finds and executes valid commands
 * @adress - Location of a command file
 * @input - what the user inputs in shell
 * @env - env variables if needed
 * return: void
 */
void execute(char *adress, char **input, char **env)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		/* Executes the command if found */
		printf("adress: %s, input: %s, env: %s\n", adress, input, env);
		if (execve(adress, input, env) == -1)
		{
			printf("Execve Error\n");
			exit(0);
		}
	}
	else
	{
		wait(NULL);
	}
	return;
}
