#include "main.h"

/**
 * execs_lines - function that sorts out the  builtins and commands in the file
 * @datash: Data relevant (args)
 * Return: 1 on success.
 */

int execs_lines(data_shell *datash)
{

	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = gets_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
