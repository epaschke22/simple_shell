#include "shell.h"

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
	while(dptr[i])
		free(dptr[i]), i++;
	if (dptr[i] == NULL)
		free(dptr[i]);
	free(dptr);
}
