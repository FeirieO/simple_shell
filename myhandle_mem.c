#include "shell.h"

/**
 **setmemo - will add all d constant bytes in memory
 *@s: pointers
 *@b: a byte
 *@n: numbs of bytes
 *Return: pointer to memo
 */
char *setmemo(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * str_free - will free all strings
 * @pp: strings
 */
void str_free(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - functions that will realloc blocks of memory
 * @ptr: pointers
 * @old_size: parameters
 * @new_size: parameters
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
