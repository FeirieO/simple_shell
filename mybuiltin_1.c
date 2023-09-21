#include "shell.h"

/**
 * cpy_hist - Will show all d history list
 * @info: structures
 *  Return: Always 0
 */
int cpy_hist(info_t *info)
{
	_plist(info->history);
	return (0);
}

/**
 * unset_alias - set an alias to d string
 * @info: parameter structs
 * @str: d strings alias
 * Return: 0 success otherwise 1
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = d_ind(&(info->alias),
		getn_ind(info->alias, _snode(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Will sets an alias
 * @info: structs
 * @str: a string
 * Return: 0 if success otherwise 1
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (end_anode(&(info->alias), str, 0) == NULL);
}

/**
 * prt_alias - Will prints an alias string
 * @node: nodes
 * Return: 0 if success otherwise 1
 */
int prt_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * cpy_alias - Will works like d builtin alias
 * @info: structures
 *  Return: 0
 */
int cpy_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			prt_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			prt_alias(_snode(info->alias, info->argv[i], '='));
	}

	return (0);
}
