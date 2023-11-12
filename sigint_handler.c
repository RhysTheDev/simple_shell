#include "main.h"
/**
* sigintHandler - handles signal when user types ctrl + c
 * @signal: signal
 *
 * Return: void
*/
void sigintHandler(int signal)
{
	(void)signal;
	printf("\n");
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
