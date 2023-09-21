#include "shell.h"

/**
 * _chain - Will checks all d current char
 * @info: structures
 * @buf: buffers
 * @p: address
 *
 * Return: 1 otherwise 0
 */
int _chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buffer_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buffer_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buffer_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * chain_check - checks frm d last status
 * @info: parameters
 * @buf: buffers
 * @p: address
 * @i: start
 * @len: buffer a length
 * Return: void
 */
void chain_check(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buffer_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buffer_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * rep_alias - Will replace all d alias
 * @info: parameters
 * Return: 1 if replaced otherwise 0
 */
int rep_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = _snode(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * rep_var - Will replace all d variables
 * @info: parameters
 * Return: 1 if replaced otherwise 0
 */
int rep_var(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			rep_str(&(info->argv[i]),
				_strdup(conv_num(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			rep_str(&(info->argv[i]),
				_strdup(conv_num(getpid(), 10, 0)));
			continue;
		}
		node = _snode(info->env, &info->argv[i][1], '=');
		if (node)
		{
			rep_str(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		rep_str(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * rep_str - replaces all d strings
 * @old: address of d old strings
 * @new: new strings
 * Return: 1 if replaced otherwise 0
 */
int rep_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
