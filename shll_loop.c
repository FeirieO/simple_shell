#include "main.h"

/**
 * no_cment - function that deletes comments from the input
 * @in: input string
 * Return: input without comments
 */

char *no_cment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1]
			    == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shll_loop -For  Loop of shell
 * @datash: Data relevant (av, input, args)
 * Return: no return.
 */

void shll_loop(data_shell *datash)
{
	int loop, i_ef;
	char *input;

	loop = 1;

	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_ef);

		if (i_ef != -1)
		{
			input = no_cment(input);
			if (input == NULL)
				continue;

			if (check_syntxs_err(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = repr_vars(input, datash);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}


	}
}
