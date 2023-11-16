#include "main.h"

/**
 * readInput - check buffer
 * @buffer_index: record of position in the buffer
 * @bs: size of buffer
 * @buffer: input data
 * @line:char array or string
 *
 * Return: updated buffer
 */
void readInput(char *buffer, size_t *buffer_index, size_t *bs, char *line)
{
	if (*buffer_index >= *bs)
	{
		*bs = read(STDIN_FILENO, buffer, MAX_INPUT_SIZE);
		if (*bs <= 0)
		{
			if (line != NULL)
				free(line);
		}
		*buffer_index = 0;
	}
}

/**
 * _getline - reads string from stdin
 * @input_size: size of buffer
 *
 * Return: input
 */
char *_getline(size_t *input_size)
{
	static char buffer[MAX_INPUT_SIZE];
	static size_t buffer_index;
	static size_t buffer_size;
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		readInput(buffer, &buffer_index, &buffer_size, line);
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
