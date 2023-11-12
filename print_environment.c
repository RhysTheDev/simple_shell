#include "main.h"
/**
 * printEnvironment - print the current environment.
 *
 * Return: void
 */
void printEnvironment(void)
{
	for (char **env = environ; *env != NULL; env++)
		printf("%s\n", *env);
}
