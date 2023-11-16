#include <sys/stat.h>
#include "main.h"

/**
 * _get_path_of_exe - get path of executable file of a command
 * @command: command passed
 *
 * Return: path to file; NULL if command doesn't exit
 */
char *_get_path_of_exe(char *command)
{
	struct stat st;
	int i;
	char *path = _getenv("PATH");
	char **dirs = tokenize_env(path);
	char *cmd = command;
	char *fullpath = malloc(sizeof(char) * 1024);

	if (fullpath == NULL)
		return (NULL);

	for (i = 0; dirs[i]; i++)
	{
		fullpath[0] = 0;
		_strcat(fullpath, dirs[i]);
		_strcat(fullpath, "/");
		_strcat(fullpath, cmd);
		if (stat(fullpath, &st) == 0)
			return (fullpath);

	}
	free(fullpath);
	return (NULL);
}
