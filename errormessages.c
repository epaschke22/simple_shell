#include "shell.h"

/**
 * _itoa - converts an int into a string
 * @value: input number
 * Return: completed string
 */
char *_itoa(int value)
{
	/*
	 * Betting there will not be an int bigger
	 * than 8 digits long
	 */
	char string[8], *result;
	int numlen = 1, numpos = 0, valcpy, mul = 1;

	valcpy = value;

	/*
	 * Count the length of the int and setting
	 * up variables at their appropiate indices
	 */
	while (valcpy >= 10)
	{
		valcpy /= 10;
		mul *= 10;
		numlen++;
	}
	/* Checks and stores one digit at a time */
	while (numlen >= 1)
	{
		/* If it is not the last digit */
		if ((value / mul) < 10)
			string[numpos] = value / mul + '0';
		else
			string[numpos] = (value / mul) % 10 + '0';
		numlen--;
		numpos++;
		mul /= 10;
	}

	/* End string with null byte */
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
	/* Basic structure of error message */
	char buffer[1024], delm[3] = ": ", nf[11] = "not found\n";

	/*
	 * Using strcpy and strcat to create the error message,
	 * there is probably a better way of doing this
	 */
	_strcpy(buffer, av);
	_strcat(buffer, delm);
	_strcat(buffer, _itoa(count));
	_strcat(buffer, delm);
	_strcat(buffer, cmd);
	_strcat(buffer, delm);
	_strcat(buffer, nf);

	/* Finally write to output */
	write(STDERR_FILENO, buffer, _strlen(buffer));
}
