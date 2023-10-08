#include "main.h"

/**
 * get_input - read input from users
 *
 * Return: ptr to str; NULL if input is null
 */

char *get_input(void)
{
	size_t len = 0;
	char *input = malloc(MAX_INPUT_SIZE);

	if (input == NULL)
		return (NULL);

	fgets(input, MAX_INPUT_SIZE, stdin);
	if (feof(stdin) != 0)
	{
		exit(0);
	}

	len = _strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';

	return (input);
}
