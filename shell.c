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
	char *buffer;

	while (status)
	{
		buffer = display_prompt();

		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(buffer, "env") == 0)
			printEnvironment();

		/* Read user buffer */
		buffer[_strcspn_(buffer, "\n")] = '\0';

		/* Fork a new process */
		pid_t pid;

		pid = fork();
		if (pid == 0)
			mainExecCommand(buffer);
		else if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else
			checkChildProcess(pid);
		free(buffer);
	}
	return (EXIT_SUCCESS);
}

