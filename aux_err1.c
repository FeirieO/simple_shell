#include "main.h"

/**
 * strcon_cd - Write a function that concatenates msg to create an err msg
 *
 * @datash: data relevant to the current directory
 * @msg: message to be included in the err message.
 * @errmsg: buffer to store the resulting err message.
 * @vers_str: string representing line counters.
 * Return: pointer to the err message.
 */
char *strcon_cd(data_shell *datash, char *msg, char *errmsg, char *vers_str)
{
	char *illegalFlag;

	_strcpy(errmsg, datash->av[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, vers_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, msg);
	if (datash->args[1][0] == '-')
	{
		illegalFlag = malloc(3);
		illegalFlag[0] = '-';
		illegalFlag[1] = datash->args[1][1];
		illegalFlag[2] = '\0';
		_strcat(errmsg, illegalFlag);
		free(illegalFlag);
	}
	else
	{
		_strcat(errmsg, datash->args[1]);
	}

	_strcat(errmsg, "\n");
	_strcat(errmsg, "\0");
	return (errmsg);
}

/**
 * errmsg_cd - generates an err message for cd command within get_cd context
 * @datash: data relevant to the current directory
 * Return: pointer to the err message or NULL if memory allocation fails
 */

char *errmsg_cd(data_shell *datash)
{
	int length, len_identifier;
	char *errmsg, *vers_str, *msg;

	vers_str = aux_itao(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_identifier = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_identifier = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(vers_str) + _strlen(msg) + len_identifier + 5;
	errmsg = malloc(sizeof(char) * (length + 1));

	if (errmsg == 0)
	{
		free(vers_str);
		return (NULL);
	}

	errmsg = strcon_cd(datash, msg, errmsg, vers_str);

	free(vers_str);

	return (errmsg);
}

/**
 * err_not_found - generic err message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: pointer to the err messages
 */
char *err_not_found(data_shell *datash)
{
	int length;
	char *errmsg;
	char *vers_str;

	vers_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(vers_str);
	length += _strlen(datash->args[0]) + 16;
	errmsg = malloc(sizeof(char) * (length + 1));
	if (errmsg == 0)
	{
		free(errmsg);
		free(vers_str);
		return (NULL);
	}
	_strcpy(errmsg, datash->av[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, vers_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, ": not found\n");
	_strcat(errmsg, "\0");
	free(vers_str);
	return (errmsg);
}

/**
 * errmsg_exit - generic err message for exit in get_exit
 * @datash: data relevant to counters and arguments
 * Return: pointer to the err message or NULL if memory allocation fails
 */
char *errmsg_exit(data_shell *datash)
{
	int length;
	char *errmsg;
	char *vers_str;

	vers_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(vers_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	errmsg = malloc(sizeof(char) * (length + 1));
	if (errmsg == 0)
	{
		free(vers_str);
		return (NULL);
	}
	_strcpy(errmsg, datash->av[0]);
	_strcat(errmsg, ": ");
	_strcat(errmsg, vers_str);
	_strcat(errmsg, ": ");
	_strcat(errmsg, datash->args[0]);
	_strcat(errmsg, ": Illegal number: ");
	_strcat(errmsg, datash->args[1]);
	_strcat(errmsg, "\n\0");
	free(vers_str);

	return (errmsg);
}
