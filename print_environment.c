#include "main.h"
/**
 * printEnvironment - print the current environment.
 *
 * Return: void
 */
void printEnvironment(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

}
