#include "shell.h"

/**
 * checkempty - checks if the input is all space
 * @input: input string to check
 * Return: 1 if true else 0
 */
int checkempty(char *input)
{
	int i;

	for (i = 0; input[i]; i++)
		if (input[i] != ' ' && input[i] != '\n')
			return (0);
	return (1);
}
