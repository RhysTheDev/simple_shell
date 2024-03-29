#include "main.h"
#define BUFSIZE 1024
/**
  * _splitline - Splits a line passed to it and stores the words into an array
  * @line: The line to be split
  *
  * Return: The array of tokens if succesful
  */

char **_splitline(char *line)
{
	int buffsize = BUFSIZE, position = 0;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;

	return (tokens);
}
