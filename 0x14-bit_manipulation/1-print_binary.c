#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << ((sizeof(unsigned long int) * 8) - 1);
	int leading_zeroes = 1;

	while (mask)
	{
	if (n & mask)
	{
	putchar('1');
	leading_zeroes = 0;
	}
	else if (!leading_zeroes)
	{
	putchar('0');
	}

	mask >>= 1;
	}

	if (leading_zeroes)
	{
	putchar('0');
	}
}

