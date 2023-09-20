#include "main.h"

/**
 * reads_lines - function that reads the input string.
 * @j_eof: Return value of getline function
 * Return: an input string
 */

char *reads_lines(int *j_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*j_eof = getline(&input, &bufsize, stdin);

	return (input);

}
