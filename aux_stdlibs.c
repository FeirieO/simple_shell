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
