#include "main.h"

/**
 * exitShell - handle exit command and its commands
 * @buffer: input from stdin
 *
 * Return: void
 */

void exitShell(char *buffer)
{
	char *tokens[MAX_INPUT_SIZE / 2 + 1];
	int token_count;
	int status;

	token_count = tokenize(buffer, tokens);
	if (token_count == 2 && _strcmp(tokens[0], "exit") == 0)
	{
		status = _atoi(tokens[1]);
		free(buffer);
		exit(status);
	}
	else
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}
