#include "shell.h"

int main()
{
	char *buffer = NULL, **input, **path, *adress;
	size_t bufsize = 0, inputsize = 0;
	int i, fd, inputCounter = 0;

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

				
				printf("The file exists!, path: %s\n", adress);
/*
				for (inputCounter = 0; input[inputCounter] != NULL; inputCounter++);
				printf("input Counter: %d, word: %s\n", inputCounter, input[inputCounter - 1]);
				char *argv[inputCounter + 1];

				inputCounter = 0;

				while (input[inputCounter] != NULL)
				{
					argv[inputCounter] = input[inputCounter];
					inputCounter++;
				}
				argv[inputCounter + 1] = NULL;

				char *argv2[] = {"ls", "-a",  NULL};
				inputCounter = 0;
				while (input[inputCounter] != NULL)
				{
					printf("count: %d, argv: %s\n", inputCounter, input[inputCounter]);
					inputCounter++;
				}
				inputCounter = 0;
				while (argv2[inputCounter] != NULL)
				{
					printf("count: %d, argv2: %s\n", inputCounter, argv2[inputCounter]);
					inputCounter++;
				}
*/
				if (execve(adress, input, NULL) == -1)
					printf("Execve Error\n");
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
