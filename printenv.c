#include <unistd.h>
#include "shell.h"
int main(int argc, char **argv, char **env)
{
	int i;
	char **envpath;

	envpath = str_to_double(getenv("PATH"), ":");
	for (i = 0; envpath[i]; i++)
		printf("%s\n", envpath[i]);
	free_double(envpath);
	return (0);
}
