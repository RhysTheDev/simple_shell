#include "main.h"

/**
 * get_input - read input from users
 * @argc: number of command line args
 * @argv: array of pointers to command line args
 *
 * Return: ptr to str; NULL if input is null
 */

char *get_input(int argc, char *argv[])
{
	size_t len = 0;
	char *command = NULL;
	char *input = malloc(MAX_INPUT_SIZE);

	if (input == NULL)
		return (NULL);

	fgets(input, MAX_INPUT_SIZE, stdin);
	if (feof(stdin) != 0)
		exit(0);

	len = _strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';

	if (argc > 1)
		command = argv[1];

	if (command != NULL)
		input = command;
	return (input);
}
