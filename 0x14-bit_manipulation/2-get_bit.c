#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @index: starting from 0 of the bit you want to get
 * Return: value of the bit
 * @n: number to search
 * Description: get_bit function that returns the value of bit at a given index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
