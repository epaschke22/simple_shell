#include "shell.h"

/**
 * runcomands - runs the commands based on input tokens
 * @input: input double pointer
 * @env: environment
 * Return: void
 */
void runcomands(char **input, char **env)
{
	char **path, *adress;
	int i, fd;

	path = str_to_double(_getenv("PATH", env), ":");
	printf("%s\n", _getenv("PATH", env));
	for (i = 0; path[i] != NULL; i++)
	{
		printf("%s\n", path[i]);
		adress = catcmd(path[i], input[0]);
		printf("%s\n", adress);
		fd = access(adress, F_OK);
		if (fd == 0)
		{
			printf("The file exists!\n");
			break;
		}
	}
	if (path[i] == NULL)
		printf("Error Number : %d\n", fd);
	free(adress);
	free_double(path);
}

/**
 * readinput - reads the user input
 * Return: double pointer of command tokens
 */
char **readinput()
{
	char *buffer = NULL, **input;
	size_t bufsize = 0, inputsize = 0;

	inputsize = getline(&buffer,&bufsize,stdin);
	input = str_to_double(buffer, " ");
	return(input);
}


/**
 * main - shell project main function
 * @ac: number of arguments
 * @av: list of arguments
 * @env: list of environment cariables
 * Return: 0 on exit, else 1 on failure
 */
int main(int ac, char *av[], char **env)
{
	char **input;
	int status = 1;
	(void)ac;
	(void)av;

	/*signal(SIGINT, SIG_IGN)*/
	while (status)
	{
		write(STDOUT_FILENO,"$ ",2);
		input = readinput();
		runcomands(input, env);
		free_double(input);
	}
	return(0);
}
