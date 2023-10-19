#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old: The size in bytes of the allocated space for ptr.
 * @new: The size in bytes for the new memory block.
 *
 * Return: If new == old - ptr.
 *         If new == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new == old)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old && index < new; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}