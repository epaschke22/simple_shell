#include "shell.h"

/**
 * shell_exit - exits shell
 * Return: void
 */
int shell_exit(void)
{
	return(-1);
}

/**
 * shell_env - prints out the environment
 * @env: environment variable
 * Return: void
 */
void shell_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
