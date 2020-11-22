#include "shell.h"

/**
 * _itoa - converts an int into a string
 * @value: input number
 * Return: completed string
 */
char *_itoa(int value)
{
	char string[8], *result;
	int numlen = 1, numpos = 0, valcpy, mul = 1;

	valcpy = value;

	while (valcpy >= 10)
	{
		valcpy /= 10;
		mul *= 10;
		numlen++;
	}
	while (numlen >= 1)
	{
		if ((value / mul) < 10)
			string[numpos] = value / mul + '0';
		else
			string[numpos] = (value / mul) % 10 + '0';
		numlen--;
		numpos++;
		mul /= 10;
	}
	string[numpos] = '\0';
	result = string;
	return (result);
}

/**
 * printerror - prints out detailed error message similar to shell
 * @av: name of program
 * @cmd: command input
 * @count: current inputline
 * Return: void
 */
void printerror(char *av, char *cmd, int count)
{
	char buffer[1024], delm[3] = ": ", nf[11] = "not found\n";

	_strcpy(buffer, av);
	_strcat(buffer, delm);
	_strcat(buffer, _itoa(count));
	_strcat(buffer, delm);
	_strcat(buffer, cmd);
	_strcat(buffer, delm);
	_strcat(buffer, nf);
	write(STDERR_FILENO, buffer, _strlen(buffer));
}
