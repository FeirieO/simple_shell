#include "main.h"

/**
 * gets_err - function that calls the err
 * according the builtin, syntax or permission
 * @datash: Data structure that contains arguments
 * @eval: the err value
 * Return: err
 */

int gets_err(data_shell *datash, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = err_env(datash);
		break;
	case 126:
		err = errmsg_path(datash);
		break;
	case 127:
		err = err_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			err = errmsg_exit(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			err = errmsg_cd(datash);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	datash->status = eval;
	return (eval);
}
