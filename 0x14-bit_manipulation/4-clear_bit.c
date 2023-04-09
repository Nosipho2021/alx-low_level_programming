#include "main.h"

/**
 * clear_bit - a function that sets the value of a bit to 0 at a given index
 * @index: starting from 0 of the bit you want to set
 * @n: pointer to the number to change
 * Return: 1 is successfull, -1 if fails
 * Description: clear_bit function sets value of a bit at a given index to 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n &= ~(1UL << index);
	return (1);
}
