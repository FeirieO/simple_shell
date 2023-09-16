#include "main.h"

/**
 * cd_shl - write a function that changes currents direcectories
 *
 * @datash: data relevant to counters and arguments
 * Return: 1 on success and NULL on failure
 */
int cd_shl(data_shell *datash)
{
	char *direc;
	int ishome, ishome2, isdsh;

	direc = datash->args[1];

	if (direc != NULL)
	{
		ishome = _strcmp("$HOME", direc);
		ishome2 = _strcmp("~", direc);
		isdsh = _strcmp("--", direc);
	}

	if (direc == NULL || !ishome || !ishome2 || !isdsh)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", direc) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", direc) == 0 || _strcmp("..", direc) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
