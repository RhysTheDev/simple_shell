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
	ssize_t read;

	read = getline(&buffer, input_size, stdin);

	if (read == -1)
	{
		free(buffer);
		write(STDOUT_FILENO, "EXITING THE SHELL AT get_input", MAX_INPUT_SIZE);
		exit(EXIT_SUCCESS);
	}

	if (buffer[read - 1] == '\n')
		buffer[read - 1] = '\0';

	return (buffer);
}
