#include "main.h"
/**
 * _strtok - split string into tokens
 * @str: string to split
 * @delim: delimiter string
 *
 * Return: token; else NULL
 */

char *_strtok(char *str, const char *delim)
{
	static char *string;
	char *token_start = NULL;

	if (str != NULL)
		string = str;

	if (string == NULL || *string == '\0')
		return (NULL);

	token_start = string;
	while (*string != '\0' && strchr(delim, *string) == NULL)
		string++;

	if (*string != '\0')
	{
		*string = '\0';
		string++;
	}

	return (token_start);
}

