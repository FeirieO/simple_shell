#include "main.h"

/**
 * _memcpy - copies data between void pointers.
 * @dest: destination pointers.
 * @src: source pointers.
 * @size: sizes of the new pointers.
 *
 * Return: null
 */
void _memcpy(void *dest, const void *src, unsigned int size)
{
	char *char_src = (char *)src;
	char *char_dest = (char *)dest;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_dest[i] = char_src[i];
}

/**
 * _realloc - reallocates a memory blocks.
 * @src: pointers to the memories previously allocated.
 * @old_size: sizes, in bytes, of the allocated space of src.
 * @new_size: new sizes, in bytes, of the new memory blocks.
 *
 * Return: src.
 * if new_size == old_size, returns src without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *src, unsigned int old_size, unsigned int new_size)
{
	void *dest;

	if (src == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(src);
		return (NULL);
	}

	if (new_size == old_size)
		return (src);

	dest = malloc(new_size);
	if (dest == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(dest, src, new_size);
	else
		_memcpy(dest, src, old_size);

	free(src);
	return (dest);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @src: double pointer to the previously allocated memory.
 * @old_size: sizes, in bytes, of the allocated memory blocks.
 * @new_size: new sizes, in bytes, for the memory blocks.
 *
 * Return: pointer to the reallocated memory.
 * if new_size == old_size, returns src without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **src, unsigned int old_size, unsigned int new_size)
{
	char **dest;
	unsigned int i;

	if (src == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (src);

	dest = malloc(sizeof(char *) * new_size);
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		dest[i] = src[i];

	free(src);

	return (dest);
}
