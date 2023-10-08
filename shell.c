#include "main.h"
#define MAX_INPUT_SIZE 1024

/**
 * main - function to initialize shell
 * @argc: number of command line args
 * @argv: array of ptrs to command line args
 *
 * Return: 1 if success; 0 if failure
 */
int main(int argc, char *argv[])
{
	while (1)
	{
		char *input;
		pid_t pid;

		display_prompt();
		input = get_input(argc, argv);
		pid = fork();
		if (input == NULL)
		{
			printf("\n");
			break;
		}

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0)
			exec_command(input);
		else
			wait_for_child(pid);

		free(input);
	}
	return (EXIT_SUCCESS);
}

