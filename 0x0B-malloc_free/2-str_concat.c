#include "main.h"
#include <stdlib.h>

/**
 * str_concat - get ends of input and add together for size
 * @s1: input one to concat
 * @s2: input two to concat
 * Return: concat of s1 and s2
 */

int get_string_length(const char *str)
{
	int length = 0;
    
	while (str[length] != '\0')
	{
	length++;
	}    
    
	return length;
}

char *str_concat(char *s1, char *s2)
{
	char *conct;
    
	if (s1 == NULL)	
	{
	s1 = "";
	}
    
	if (s2 == NULL)
	{
	s2 = "";
	}
    
	int s1_length = get_string_length(s1);
	int s2_length = get_string_length(s2);
    
	conct = malloc(sizeof(char) * (s1_length + s2_length + 1));
    
	if (conct == NULL)
	{
	return NULL;
	}
    
	int i = 0, ci = 0;
    
	while (s1[i] != '\0')
	{
	conct[i] = s1[i];
	i++;
	}
    
	while (s2[ci] != '\0')
	{
	conct[i] = s2[ci];
	i++;
	ci++;
	}
    
	conct[i] = '\0';
    
	return conct;
}
