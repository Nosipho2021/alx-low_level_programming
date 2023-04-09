#include "main.h"

/**
 * get_endianness -  function that checks the endianness
 * Return: 0 if big endian, 1 if little endian
 * Description: get_endianness function that checks endianness
 */
int get_endianness(void)
{
	unsigned int x = 0x01234567;
	unsigned char *ptr = (unsigned char *)&x;

	if (*ptr == 0x67)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
