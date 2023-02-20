#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float e;

	printf("Size of a char: %u byte(s)", sizeof(a));
	printf("Size of an int: %u byte(s)", sizeof(b));
	printf("Size of a long int: %u byte(s)", sizeof(c));
	printf("Size of a long long int: %u byte(s)", sizeof(d));
	printf("Size of a float: %u byte(s)", sizeof(e));
	return (0);


}
