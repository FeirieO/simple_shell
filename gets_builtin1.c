#include "main.h"

/**
 * gets_builtin - for pairing the command in the arg
 * @cmds: command
 * Return: Function pointer of the builtin command
 */

int (*gets_builtin(char *cmds))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shl },
		{ "help", gets_helps},
		{ NULL, NULL }
	};
	int j;

	for (j = 0; builtin[j].name; j++)
	{
		if (_strcmp(builtin[j].name, cmds) == 0)
			break;
	}

	return (builtin[j].f);
}
