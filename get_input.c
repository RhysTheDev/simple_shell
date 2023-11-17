#include "main.h"

/**
 * get_input - read input from users
 * @input_size: size of the buffer
 *
 * Return: ptr to str; NULL if input is null
 */

char *get_input(size_t *input_size)
{
	char *buffer = NULL;

	buffer = _getline(input_size);
	if (buffer == NULL)
	{
		/* Handle end-of-file or read error */
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
