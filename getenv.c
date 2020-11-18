#include "shell.h"

/**
 * _getenv - gets a string of the designated path location
 * @section: the string to look for in the environment
 * @envir: the environment variable
 * Return: return the string of the section in the environment
 */
char *_getenv(char *section, char **env)
{
	char *envtoken, *envpart, *result;
	int i, j, flag = 1;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; section[j]; j++)
			if (env[i][j] != section[j])
				flag = 1;
		if (flag == 0)
		{
			envpart = malloc((_strlen(env[i]) + 1) * sizeof(char));
			if (envpart == NULL)
				return (NULL);
			_strcpy(envpart, env[i]);
			envtoken = strtok(envpart, "=");
			envtoken = strtok(NULL, "\n");
			result = malloc((_strlen(envtoken) + 1) * sizeof(char));
			if (result == NULL)
				return (NULL);
			_strcpy(result, envtoken);
			free(envpart);
			return (result);
		}
		flag = 0;
	}
	return (NULL);
}
