#include "shell.h"

int main()
{
	char *buffer = NULL, **input, **path, *adress;
	size_t bufsize = 0, inputsize = 0;
	int i, fd;

	path = str_to_double(getenv("PATH"), ":");
	while (1)
	{
		write(STDOUT_FILENO,"$ ",2);
		inputsize = getline(&buffer,&bufsize,stdin);
		input = str_to_double(buffer, " ");
		for (i = 0; path[i] != NULL; i++)
		{
			adress = catcmd(path[i], input[0]);
			fd = access(adress, F_OK);
			if (fd == 0)
			{
				printf("The file exists!\n");
				break;
			}
		}
		if (path[i] == NULL)
			printf("Error Number : %d\n", fd);
		free_double(input);
		free(adress);
	}
	return(0);
}
