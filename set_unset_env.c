#include "main.h"
/**
 * setEnvVar - set environmental variable
 * @buffer: input from user
 *
 * Return: 1 on success; else -1
 */

int setEnvVar(char *buffer)
{
	char *tokens[MAX_INPUT_SIZE / 2 + 1];
	int token_count;

	token_count = tokenize(buffer, tokens);
	if (token_count == 3)
	{
		if (setenv(tokens[1], tokens[2], 1) == 0)
			return (0);
		else
			return (-1);
	}
}
