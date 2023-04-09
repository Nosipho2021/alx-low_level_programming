#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned integer
 * @b: pointing to a string of 0 and 1 char
 * Return: 0 b is NULL, not 0 or 1 and one or more chars in the string
 * Description: binary_to_uint function that converts a binary number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (; *b; b++)
	{
		if (*b == '0')
			result = (result << 1);
		else if (*b == '1')
			result = (result << 1) | 1;
		else
			return (0);
	}

	return (result);
}

