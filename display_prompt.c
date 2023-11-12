#include "main.h"

/**
 * display_prompt - display the prompt on initialization
 *
 * Return: None
 */

char *display_prompt(void)
{
	int status = 1;
	size_t input_size = MAX_INPUT_SIZE;
	char *buffer;

	status = isatty(STDIN_FILENO);
	if (status == -1)
		write(STDOUT_FILENO, "$ ", 2);

	buffer = get_input(&input_size);

	return (buffer);

}

