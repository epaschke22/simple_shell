#include "shell.h"

/**
 * _strlen - returns string length
 * @s: input string pointer
 * Return: int of length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: destination of the copied string
 * @src: the source of the string to be copied
 * Return: destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates 2 strings
 * @dest: the combined output of both strings
 * @src: the string to be combined
 * Return: returns the combined strings
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	len = _strlen(dest);

	for (i = 0; src[i]; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares 2 strings for being the same
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: 1 if same, 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strdup - duplicates a string into an empty string
 * @dest: destination of the duplicated string
 * @src: the source of the string to be duplicated
 * Return: destination string
 */
char *_strdup(char *dest, char *src)
{
	dest = malloc((_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	_strcpy(dest, src);
	return (dest);
}
