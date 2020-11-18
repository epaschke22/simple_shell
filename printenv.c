#include <unistd.h>
#include "shell.h"

int main(int argc, char **argv, char **env)
{
	int i;
	char **envpath;
	char *test, *cat;

	test = _getenv("PATH", env);
	printf("%s\n", test);
	envpath = str_to_double(test, ":");
	free(test);
	for (i = 0; envpath[i]; i++)
	{
		cat = catcmd(envpath[i], "ls");
		printf("%s\n", cat);
		free(cat);
	}
	free_double(envpath);
	return (0);
}
