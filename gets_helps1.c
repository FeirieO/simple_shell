#include "main.h"

/**
 * gets_helps - function that retrieves help messages according builtin
 * @datashe: Data structure (args and input)
 * Return: Return 0
*/

int gets_helps(data_shell *datashe)
{

	if (datashe->args[1] == 0)
		aux_help_general();
	else if (_strcmp(datashe->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(datashe->args[1], "env") == 0)
		aux_help_env();
	else if (_strcmp(datashe->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(datashe->args[1], "help") == 0)
		aux_help();
	else if (_strcmp(datashe->args[1], "exit") == 0)
		aux_help_exit();
	else if (_strcmp(datashe->args[1], "cd") == 0)
		aux_help_cd();
	else if (_strcmp(datashe->args[1], "alias") == 0)
		aux_help_alias();
	else
		write(STDERR_FILENO, datashe->args[0],
		      _strlen(datashe->args[0]));

	datashe->status = 0;
	return (1);
}
