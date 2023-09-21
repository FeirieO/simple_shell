#include "main.h"

/**
 * is_crdir - checks ":" if is in the current directory.
 * @pth: pth string.
 * @i: index pointer
 * Return: 1 if the pth is searchable in the current directory, 0 otherwise.
 */

int is_crdir(char *pth, int *i)
{
	if (pth[*i] == ':')
		return (1);

	while (pth[*i] != ':' && pth[*i])
	{
		*i += 1;
	}

	if (pth[*i])
		*i += 1;

	return (0);
}

/**
 * _which - locates a command.
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command.
 */

char *_which(char *cmd, char **_environ)
{
	char *pth, *ptr_pth, *token_pth, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	pth = _getenv("pth", _environ);
	if (pth)
	{
		ptr_pth = _strdup(pth);
		len_cmd = _strlen(cmd);
		token_pth = _strtok(ptr_pth, ":");
		i = 0;
		while (token_pth != NULL)
		{
			if (is_crdir(pth, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_pth);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_pth);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_pth);
				return (dir);
			}
			free(dir);
			token_pth = _strtok(NULL, ":");
		}
		free(ptr_pth);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - function that determines if a file is executable
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */

int is_executable(data_shell *datash)
{
	struct stat st;
	int i;
	char *input;

	input = datash->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	gets_err(datash, 127);
	return (-1);
}

/**
 * check_err_cmd - verifies if the user has permissions to access a command.
 * @dir: Destination directory
 * @datash: data structure
 * Return: 1 if there is an err, NULL if not
 */

int check_err_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		gets_err(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			gets_err(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			gets_err(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - executes command lines
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */

int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash->args[0], datash->_environ);
		if (check_err_cmd(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->args[0], datash->_environ);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
