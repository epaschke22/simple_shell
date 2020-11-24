#include "shell.h"

/**
 * shell_exit - exits shell
 * @env: input
 * Return: void
 */
int shell_exit(char **env)
{
	/*
	 * Now after analyzing this code, this could have
	 * been implemented without this function pointer
	 */
	(void)env;
	exit(EXIT_SUCCESS);
}

/**
 * shell_env - prints out the environment
 * @env: environment variable
 * Return: void
 */
int shell_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
