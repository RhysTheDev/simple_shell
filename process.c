#include "main.h"

/**
 * exec_command -  execute command passed
 * @input: string command input by user
 *
 * Return: None
 */
void exec_command(char *input, char **command_args)
{
	if (execve(input, command_args, NULL) == -1)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
}

/**
 * wait_for_child -  takes PID of child process and waits for it to end
 * @pid: PID of the child process to wait for
 *
 * Return: None
 */
void wait_for_child(pid_t pid)
{
	int status = 0;

	if (waitpid(pid, &status, 0) == -1)
		perror("waitpid");
}

