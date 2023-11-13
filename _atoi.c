#include "main.h"
/**
 * _atoi - convert string to int
 * @str: pointer to char
 *
 * Return: int
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	if (*str == '-')
	{
		sign = -1;
		str++;
	} else if (*str == '+')
		str++;

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (sign * result);
}
