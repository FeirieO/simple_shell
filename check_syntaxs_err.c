#include "main.h"

/**
 * repetd_char - count the repetitions of a character in a string
 * @inpt: inpt string
 * @i: index
 * Return: repetitions
 */

int repetd_char(char *inpt, int i)
{
	if (*(inpt - 1) == *inpt)
		return (repetd_char(inpt - 1, i + 1));

	return (i);
}

/**
 * err_sep_op - finding syntxs errs
 * @inpt: inpt string
 * @i: index
 * @lst: lst char read
 * Return: index of error, 0 when there are no errors.
 * errs
 */

int err_sep_op(char *inpt, int i, char lst)
{
	int count;

	count = 0;
	if (*inpt == '\0')
		return (0);

	if (*inpt == ' ' || *inpt == '\t')
		return (err_sep_op(inpt + 1, i + 1, lst));

	if (*inpt == ';')
		if (lst == '|' || lst == '&' || lst == ';')
			return (i);

	if (*inpt == '|')
	{
		if (lst == ';' || lst == '&')
			return (i);

		if (lst == '|')
		{
			count = repetd_char(inpt, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*inpt == '&')
	{
		if (lst == ';' || lst == '|')
			return (i);

		if (lst == '&')
		{
			count = repetd_char(inpt, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (err_sep_op(inpt + 1, i + 1, *inpt));
}

/**
 * first_char - Finds index of the first char
 * @inpt: inpt string
 * @i: index
 * Return: 1 if there is an err. 0 in other case.
 */

int first_char(char *inpt, int *i)
{

	for (*i = 0; inpt[*i]; *i += 1)
	{
		if (inpt[*i] == ' ' || inpt[*i] == '\t')
			continue;

		if (inpt[*i] == ';' || inpt[*i] == '|' || inpt[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntxs_err - print a syntax error message.
 * @datash: data structure
 * @inpt: inpt string
 * @i: index of the err
 * @bool: to control msg err
 * Return: no return
 */

void print_syntxs_err(data_shell *datash, char *inpt, int i, int bool)
{
	char *msg, *msg2, *msg3, *err, *counter;
	int length;

	if (inpt[i] == ';')
	{
		if (bool == 0)
			msg = (inpt[i + 1] == ';' ? ";;" : ";");
		else
			msg = (inpt[i - 1] == ';' ? ";;" : ";");
	}

	if (inpt[i] == '|')
		msg = (inpt[i + 1] == '|' ? "||" : "|");

	if (inpt[i] == '&')
		msg = (inpt[i + 1] == '&' ? "&&" : "&");

	msg2 = ": syntxs err: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(counter);
		return;
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, counter);
	_strcat(err, msg2);
	_strcat(err, msg);
	_strcat(err, msg3);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, length);
	free(err);
	free(counter);
}

/**
 * check_syntxs_err - intermediate function to
 * find and print a syntxs err
 * @datash: data structure
 * @inpt: inpt string
 * Return: 1 if there is an err. 0 in other case
 */

int check_syntxs_err(data_shell *datash, char *inpt)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(inpt, &begin);
	if (f_char == -1)
	{
		print_syntxs_err(datash, inpt, begin, 0);
		return (1);
	}

	i = err_sep_op(inpt + begin, 0, *(inpt + begin));
	if (i != 0)
	{
		print_syntxs_err(datash, inpt, begin + i, 1);
		return (1);
	}

	return (0);
}
