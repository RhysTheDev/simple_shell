#include "main.h"
/**
* _strcspn_ - search a string for a set of bytes
 * @str: string to be searched
 * @reject: characters to be exclude
 *
 * Return: length of str that doesn't have reject chars
*/
int _strcspn_(const char *str, const char *reject)
{
	const char *s;
	const char *r;
	int count = 0;

	for (s = str; *s != '\0'; ++s)
	{
		for (r = reject; *r != '\0'; ++r)
		{
			if (*s == *r)
				return (count);
		}
		++count;
	}
	return (count);
}

