#include "main.h"

/**
 * exit_shell - function to exit the shell
 * @datashe: Data relevant (status and args)
 * Return: 0 on success.
 */

int exit_shell(data_shell *datashe)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datashe->args[1] != NULL)
	{
		ustatus = _atoi(datashe->args[1]);
		is_digit = _isdigit(datashe->args[1]);
		str_len = _strlen(datashe->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;

		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datashe, 2);
			datashe->status = 2;
			return (1);
		}
		datashe->status = (ustatus % 256);
	}
	return (0);
}
