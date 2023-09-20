#include "main.h"

/**
 * execs_lines - finction that finds builtins and commands
 * @datashe: Data relevant (args)
 * Return: 1 on success.
 */

int execs_lines(data_shell *datashe)
{

	int (*builtin)(data_shell *datashe);

	if (datashe->args[0] == NULL)
		return (1);

	builtin = get_builtin(datashe->args[0]);

	if (builtin != NULL)
		return (builtin(datashe));

	return (cmd_exec(datashe));
}
