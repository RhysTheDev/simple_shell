#include "main.h"
/**
 * _strcnpy - copy string
 * @dest: pointer to buffer destination
 * @src: pointer to string being copied
 * @n: number of chars to copy
 *
 * Return: pointer to dest
 */
#include <stdio.h>

void _strcnpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; ++i)
		dest[i] = src[i];

	for (; i < n; ++i)
		dest[i] = '\0';
}
