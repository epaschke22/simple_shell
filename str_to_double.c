#include "shell.h"

/**
 * str_to_double - takes a string and outputs a double pointe
 * @input: input string to split up
 * @delm: delimiter to seperate the input
 * Return: double pointer
 */
char **str_to_double(char *input, char *delm)
{
	char **output, *item;
	unsigned int cmdlen = 0, i;

	for (i = 0; input[i]; i++)
		if (input[i] == delm[0])
			cmdlen++;
	output = malloc(sizeof(char *) * (cmdlen + 1));
	if (output == NULL)
		return(NULL);
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
	return(output);
}
