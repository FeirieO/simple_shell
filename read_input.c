#include "main.h"

/**
 * read_line - function that reads the input string.
 * @i_ef: Return value of getline function
 * Return: input string
 */

char *read_line(int *i_ef)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_ef = getline(&input, &bufsize, stdin);

	return (input);

}

