#include "main.h"

/**
 * gets_helps - function that retrieves help messages according builtin
 * @datash: Data structure (args and input)
 * Return: Return 0
*/

int gets_helps(data_shell *datash)
{

	if (datash->args[1] == 0)
		aux_helper_gen();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_helper_setenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		aux_helper_env();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_helper_unsetenv();
	else if (_strcmp(datash->args[1], "help") == 0)
		aux_helper();
	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_helper_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		aux_helper_cd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		aux_helper_alias();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
