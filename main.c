#include "main.h"
#define MAX_INPUT_SIZE 1024

/**
 * main - function to initialize shell
 *
 * Return: 1 if success; 0 if failure
 */
int main(void)
{
	int status = 1;
	char **arguments;
	char *buffer;

	while (status)
	{
		buffer = display_prompt();

		if (_strcmp(buffer, "exit") == 0)
		{
			exitShell(buffer);
		}
		if (_strcmp(buffer, "env") == 0)
			printEnvironment();

		arguments = _splitline(buffer);
		if (arguments == NULL)
		{
			free(buffer);
			free(arguments);
			continue;
		}
		execute(arguments);
		free(buffer);
		free(arguments);
	}
	return (0);
}

