#include "main.h"

/**
 * gets_err - function that calls the err
 * according the builtin, syntax or permission
 * @datashe: Data structure that contains arguments
 * @eval: the err value
 * Return: err
 */

int gets_err(data_shell *datashe, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = err_env(datashe);
		break;
	case 126:
		err = err_path_126(datashe);
		break;
	case 127:
		err = err_not_found(datashe);
		break;
	case 2:
		if (_strcmp("exit", datashe->args[0]) == 0)
			err = err_exit_shell(datashe);
		else if (_strcmp("cd", datashe->args[0]) == 0)
			err = err_gets_cd(datashe);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	datashe->status = eval;
	return (eval);
}
