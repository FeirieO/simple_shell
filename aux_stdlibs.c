#include "main.h"

/**
 * get_length - Get the lenghts of numbers.
 * @b: type int numbers.
 * Return: Lenghts of numbers.
 */
int get_length(int b)
{
	unsigned int b1;
	int lenght = 1;

	if (b < 0)
	{
		lenght++;
		b1 = b * -1;
	}
	else
	{
		b1 = b;
	}
	while (b1 > 9)
	{
		lenght++;
		b1 = b1 / 10;
	}

	return (lenght);
}

/**
 * aux_itao - function that converts int to strings.
 * @b: type int numbers
 * Return: pointer to the strings.
 */
char *aux_itao(int b)
{
	unsigned int b1;
	int lenght = get_length(b);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (b < 0)
	{
		b1 = b * -1;
		buffer[0] = '-';
	}
	else
	{
		b1 = b;
	}

	lenght--;
	do {
		*(buffer + lenght) = (b1 % 10) + '0';
		b1 = b1 / 10;
		lenght--;
	}
	while (b1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a strings to an integer.
 * @t: input strings.
 * Return: integers.
 */
int _atoi(char *t)
{
	unsigned int count = 0, size = 0, oi = 0, pb = 1, m = 1, i;

	while (*(t + count) != '\0')
	{
		if (size > 0 && (*(t + count) < '0' || *(t + count) > '9'))
			break;

		if (*(t + count) == '-')
			pb *= -1;

		if ((*(t + count) >= '0') && (*(t + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(t + i) - 48) * m);
		m /= 10;
	}
	return (oi * pb);
}
