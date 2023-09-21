#include "main.h"

/**
 * cmprs_env - compare environment variable names
 * @nenvs: Name of the environment variable
 * @name: name to compare
 * Return: 0 if are not equal, otherwise the number of characters matched.
 */

int cmprs_env(const char *nenvs, const char *name)

{

	int i;

	for (i = 0; nenvs[i] != '='; i++)

	{

		if (nenvs[i] != name[i])

		{

			return (0);

		}
	}

	return (i + 1);

}

/**
 * _getenv - get the value of an environment variable.
 * @name: Name of the environment variable
 * @_environ: pointer to the environment variables array.
 * Return: Pointer to the value of the environment variable if found, 
 * otherwise NULL.
 */

char *_getenv(const char *name, char **_environ)

{

	char *ptr_env;

	int i, mov;



	/* Initialize ptr_env value */

	ptr_env = NULL;
	mov = 0;

	/* Compare all environment variables */

	/* environ is declared in the header file */

	for (i = 0; _environ[i]; i++)
	{
		/* If name and env are equal */
		mov = cmprs_env(_environ[i], name);

		if (mov)

		{
			ptr_env = _environ[i];
			break;
		}

	}

	return (ptr_env + mov);
}



/**
 * _env - print the environment variables.
 * @datash: Data structure.
 * Return: 1 on success.
 */

int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)

	{

		for (j = 0; datash->_environ[i][j]; j++)

			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);

	}

	datash->status = 0;
	return (1);
}
