#include "main.h"

/**
 * brings_liners -function that assigns the line var for get_line
 * @liners: Buffer to store the input str
 * @buffers: The str that is been called to line
 * @n: size of line
 * @k: size of buffers
 */

void brings_liners(char **liners, size_t *n, char *buffers, size_t k)
{

	if (*liners == NULL)
	{
		if  (k > BUFSIZE)
			*n = k;

		else
			*n = BUFSIZE;
		*liners = buffers;
	}
	else if (*n < k)
	{
		if (k > BUFSIZE)
			*n = k;
		else
			*n = BUFSIZE;
		*liners = buffers;
	}
	else
	{
		_strcpy(*liners, buffers);
		free(buffers);
	}
}

/**
 * gets_liner - function that Read input from stream
 * @liners: Buffer that stores the input
 * @n: size of liners
 * @streamer: stream to read from
 * Return: The number of bytes
 */

ssize_t gets_liner(char **liners, size_t *n, FILE *streamer)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffers;
	char t = 'z';

	if (input == 0)
		fflush(streamer);
	else
		return (-1);
	input = 0;

	buffers = malloc(sizeof(char) * BUFSIZE);
	if (buffers == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);

		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffers);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffers = _realloc(buffers, input, input + 1);
		buffers[input] = t;
		input++;
	}
	buffers[input] = '\0';
	brings_liners(liners, n, buffers, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
