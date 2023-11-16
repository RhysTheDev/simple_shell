#include "main.h"

/**
 * checkChildProcess -  takes PID of child process and waits for it to end
 * @pid: PID of the child process to wait for
 *
 * Return: None
 */
void checkChildProcess(pid_t pid)
{
	int status = 0;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Error waiting for child process");
		exit(EXIT_FAILURE);
	}

	/* Check if the child process exited successfully */
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		write(STDERR_FILENO, "Error: Command not found\n", 25);
}
