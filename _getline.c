#include "main.h"
/**
 * _getline - reads string from stdin
 * @input_size: size of buffer
 *
 * Return: input
 */
static char buffer[MAX_INPUT_SIZE];
static size_t buffer_index;
static size_t buffer_size;

char *_getline(size_t *input_size)
{
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, MAX_INPUT_SIZE);
			if (buffer_size <= 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
			buffer_index = 0;
		}
		if (line_size <= 0 || line == NULL)
		{
			line_size += MAX_INPUT_SIZE;
			line = realloc(line, line_size);
			if (line == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		while (buffer_index < buffer_size)
		{
			if (buffer[buffer_index] == '\n')
			{
				line[line_size - 1] = '\0';
				buffer_index++;
				*input_size = line_size - 1;
				return (line);
			}
			line[line_size - MAX_INPUT_SIZE + buffer_index] = buffer[buffer_index];
			buffer_index++;
		}
	}
}
