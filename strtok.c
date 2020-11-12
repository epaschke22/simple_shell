#include "shell.h"

/**
 * main - does a thing
 * Return: always 0
 */
int main(void)
{
	char inputstr[18] = "This is a command";
	char **output, *item, *input;
	unsigned int cmdlen = 0, i = 0;

	input = inputstr;

	for (i = 0; input[i]; i++)
		if (input[i] == ' ')
			cmdlen++;
	printf("bug0\n");
	output = malloc(sizeof(char *) * (cmdlen + 1));
	if (output == NULL)
		return(-1);
	printf("bug1\n");
	item = strtok(input, " ");
	printf("bug2\n");
	i = 0;
	while (item != NULL)
	{
		printf("bug3\n");
		output[i] = malloc(sizeof(char) * (_strlen(item) + 1));
		if (output[i] == NULL)
		{
			free_double(output);
			return (-1);
		}
		_strcpy(output[i], item);
		item = strtok(NULL, " ");
		i++;
	}
	output[i] = NULL;

	for (i = 0; output[i] != NULL; i++)
		printf("%s\n", output[i]);
	free_double(output);
	return(0);
}
