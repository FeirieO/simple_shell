#include "main.h"

/**
 * err_env - generate an err messages for env.
 * @datash: data relevant to counters and arguments
 * Return: pointer to the err messages.
 */
char *err_env(data_shell *datash)
{
	int length;
	char *errmsg;
	char *vers_str;
	char *msg;

	vers_str = aux_itoa(datash->counter);
	msg = ": Unable to remove or add from environment\n";
	length = _strlen(datash->av[0]) + _strlen(vers_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
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
	_strcat(errmsg, msg);
	_strcat(errmsg, "\0");
	free(vers_str);

	return (errmsg);
}

/**
 * errmsg_path - Generates an err msg for permission denied (error code 126)
 * @datash: data relevants to current command exec (counter, arguments).
 *
 * Return: pointer to the err msg string or NULL if memory allocation fails.
 */
char *errmsg_path(data_shell *datash)
{
	int length;
	char *vers_str;
	char *errmsg;

	vers_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(vers_str);
	length += _strlen(datash->args[0]) + 24;
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
	_strcat(errmsg, ": Permission denied\n");
	_strcat(errmsg, "\0");
	free(vers_str);
	return (errmsg);
}
