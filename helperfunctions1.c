#include "shell.h"

/**
 * catcmd - combines command with path adress
 * @path: adress to add command to
 * @cmd: command to add onto
 * Return: new combined string
 */
char *catcmd(char *path, char *cmd)
{
	int len, i;
	char *newpath, slash = '/';

	len = _strlen(path);

	for (i = 0; cmd[i] != '\0'; i++)
		if (cmd[i] == '\n')
			cmd[i] = '\0';
	newpath = malloc(sizeof(char) * (len + 2 + _strlen(cmd)));
	if (newpath == NULL)
		return (NULL);
	_strcpy(newpath, path);
	newpath[len] = slash;
	len++;
	for (i = 0; cmd[i]; i++)
		newpath[len + i] = cmd[i];
	newpath[len + i] = '\0';
	return (newpath);
}

/**
 * _getenv - gets a string of the designated path location
 * @section: the string to look for in the environment
 * @env: the environment variable
 * Return: return the string of the section in the environment
 */
char *_getenv(char *section, char **env)
{
	char *envtoken, *envpart = NULL, *result = NULL;
	int i, j, flag = 1;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; section[j]; j++)
			if (env[i][j] != section[j])
				flag = 1;
		if (flag == 0)
		{
			envpart = _strdup(envpart, env[i]);
			envtoken = strtok(envpart, "=");
			envtoken = strtok(NULL, "\n");
			result = _strdup(result, envtoken);
			free(envpart);
			return (result);
		}
		flag = 0;
	}
	return (NULL);
}

/**
 * str_to_double - takes a string and outputs a double pointe
 * @input: input string to split up
 * @delm: delimiter to seperate the input
 * Return: double pointer
 */
char **str_to_double(char *input, char *delm)
{
	char **output, *item;
	unsigned int cmdlen = 0, i = 0;

	for (i = 0; input[i]; i++)
		if (input[i] == delm[0])
			cmdlen++;
	output = malloc(sizeof(char *) * (cmdlen + 2));
	if (output == NULL)
		return (NULL);
	item = strtok(input, delm);
	for (i = 0; item != NULL; i++)
	{
		output[i] = malloc(sizeof(char) * (_strlen(item) + 1));
		if (output[i] == NULL)
		{
			free_double(output);
			return (NULL);
		}
		_strcpy(output[i], item);
		item = strtok(NULL, delm);
	}
	output[i] = NULL;
	return (output);
}

/**
 * free_double - frees up all allocated space of a double pointer
 * @dptr: double pointer to free.
 * Return: void
 */
void free_double(char **dptr)
{
	unsigned int i = 0;

	if (dptr == NULL)
		return;
	while (dptr[i])
		free(dptr[i]), i++;
	if (dptr[i] == NULL)
		free(dptr[i]);
	free(dptr);
}

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
		if (execve(adress, input, env) == -1)
		{
			perror("Execve Error");
			exit(0);
		}
	}
	else
		wait(NULL);
	return;
}
