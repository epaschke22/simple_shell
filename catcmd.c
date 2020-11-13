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

	for (i = 0; cmd[i]; i++)
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
