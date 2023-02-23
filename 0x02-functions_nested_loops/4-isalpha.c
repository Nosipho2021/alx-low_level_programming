#include "main.h"

int _isalpha(int c)
{
	char letter = 'a';

	while (letter <= 'z')
	{

		if ((c == 'a' || c >= 'd'))
		{

			return (1);
		}
	letter++;
	}

			return (0);
}
