#include "shell.h"

/**
 * _getenv - gets a string of the designated path location
 * @section: the string to look for in the environment
 * @envir: the environment variable
 * Return: return the string of the section in the environment
 */
char *_getenv(char *section, char **envir)
{
	char *envtoken, *malsect;
	int i;

	malsect = malloc(_strlen(section) * sizeof(char));
	if (malsect == NULL)
		return(NULL);
	malsect = _strcpy(malsect, section);

	for (i = 0; envir[i]; i++)
	{
		envtoken = strtok(envir[i], "=");
		if (_strcmp(envtoken, malsect))
		{
			envtoken = strtok(NULL, "=");
			free(malsect);
			return(envtoken);
		}
	}
	free(malsect);
	return (NULL);
}
