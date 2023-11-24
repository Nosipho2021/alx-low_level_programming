#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @m: first number
 * @n: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int m, unsigned long int n)
{
	int a, countbit = 0;
	unsigned long int current;
	unsigned long int exclusive = m ^ n;

	for (a = 63; a >= 0; a--)
	{
		current = exclusive >> a;
		if (current & 1)
			countbit++;
	}

	return (countbit);
}

