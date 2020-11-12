#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char *buffer = NULL;
	size_t bufsize = 0, inputsize = 0;

	while (1)
	{
		write(STDOUT_FILENO,"$ ",2);
		inputsize = getline(&buffer,&bufsize,stdin);
		write(STDOUT_FILENO,buffer,inputsize);
	}
	return(0);
}
