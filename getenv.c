#include "shell.h"

/**
 * _getenv - gets a string of the designated path location
 * @section: the string to look for in the environment
 * @envir: the environment variable
 * Return: return the string of the section in the environment
 */
char *_getenv(char *section, char **env)
{
	char *envtoken, *envpart, *malsect;
	int i, j, len, flag = 1;

	malsect = malloc(_strlen(section) * sizeof(char));
	if (malsect == NULL)
		return(NULL);
	malsect = _strcpy(malsect, section);

	for (i = 0; env[i]; i++)
	{
		for (j = 0; env[i][j] != '='; j++)
			if (env[i][j] != malsect[j])
				flag = 1;
		if (flag == 0)
		{
			envpart = malloc((_strlen(env[i]) + 1) * sizeof(char));
			if (envpart == NULL)
				return (NULL);
			_strcpy(envpart, env[i]);
			envtoken = strtok(envpart, "=");
			envtoken = strtok(NULL, "\n");
			free(malsect);
			return (envtoken);
		}
		flag = 0;
		len = 0;
	}
	free(malsect);
	return (NULL);
}
