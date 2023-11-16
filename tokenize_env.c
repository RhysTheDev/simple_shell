#include "main.h"

/**
  * tokenize_env - Tokenize the PATH to return a list of folders
  * @path: The path string to cnvert to an array
  *
  * Return: An array of the directories
  */

char **tokenize_env(char *path)
{
	char *path_copy = path;
	int i = 0;
	char *token;

	static char *arr[20] = {NULL};


	if (path == NULL)
		return (NULL);

	token = _strtok(path_copy, ":");
	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, ":");
	}


	return (arr);
}
