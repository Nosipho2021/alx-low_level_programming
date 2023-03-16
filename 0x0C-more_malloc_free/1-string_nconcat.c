#include <stdlib.h>

#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{

	if (!s1)
	s1 = "";
	if (!s2)
	s2 = "";

	unsigned int len1 = 0;
	{
	while (s1[len1])
	}
	len1++;

	char *s = malloc(sizeof(char) * (len1 + n + 1));
	{
	if (!s)
	}
	return (NULL);

	unsigned int i, j;
	{
	for (i = 0; s1[i]; i++)
	}
	s[i] = s1[i];
	{
	for (j = 0; j < n && s2[j]; j++)
	s[i + j] = s2[j];
	s[i + j] = '\0';
	}
	return (s);

}
