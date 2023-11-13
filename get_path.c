#include "main.h"

/**
 * _get_path_of_exe - get path of executable file of a command
 * @command: command passed
 *
 * Return: path to file; NULL if command doesn't exit
 */
char *_get_path_of_exe(char *command)
{
	char *path, *token, *full_path, *executable;

	executable = NULL;
	path = _getenv("PATH");
	token = _strtok(path, ":");

	if (path == NULL)
		return (NULL);
	while (token != NULL)
	{
		full_path = malloc(_strlen(token) + _strlen(command) + 2);
		if (full_path == NULL)
			return (NULL);
		if (access(full_path, F_OK) == 0)
		{
			executable = full_path;
			break;
		}
		free(full_path);
		token = _strtok(NULL, ":");
	}
	return (executable);
}
