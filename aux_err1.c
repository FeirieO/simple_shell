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
