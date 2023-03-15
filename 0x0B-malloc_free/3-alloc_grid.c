#include "main.h"
#include <stdlib.h>

/**
* str_len - get length of a string
*
* @s: string input
*
* Return: length of s
*/

unsigned int str_len(char *s)
{
	unsigned int len = 0;

	while (*s++)
	len++;

	return (len);
}

/**
* create_conct - concatenate s1 and s2 into a new string
*
* @s1: input one to concat
*
* @s2: input two to concat
*
* @len1: length of s1
*
* @len2: length of s2
*
* Return: pointer to new string containing s1 and s2
*/

char *create_conct(char *s1, char *s2, unsigned int len1, unsigned int len2)
{
	char *conct = malloc(sizeof(char) * (len1 + len2 + 1));
	unsigned int i = 0, j = 0;

	if (!conct)
	return (NULL);

	while (i < len1)
	{
	conct[i] = s1[i];
	i++;
	}

	while (j < len2)
	{
	conct[i] = s2[j];
	i++, j++;
	}

	conct[i] = '\0';

	return (conct);
}

/**
* str_concat - get ends of input and add together for size
*
* @s1: input one to concat
*
* @s2: input two to concat
*
* Return: concat of s1 and s2
*/

char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0, len2 = 0;

	if (!s1)
	s1 = "";

	if (!s2)
	s2 = "";

	len1 = str_len(s1);
	len2 = str_len(s2);

	return (create_conct(s1, s2, len1, len2));
}
/**
*free_grid - free memory allocated for grid
*
* @grid: grid to free
*
* @height: height of grid
*/

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	free(grid[i]);

	free(grid);
}

/**
* alloc_grid - allocate memory for a 2D array
*
* @width: width input
*
* @height: height input
*
* Return: pointer to 2 dim. array
*/

int **alloc_grid(int width, int height)
{
	int **grid = NULL;
	int i, j;

	if (width <= 0 || height <= 0)
	return (NULL);

	 grid = malloc(sizeof(int *) * height);

	if (!grid)
	return (NULL);

	for (i = 0; i < height; i++)
	{
	grid[i] = malloc(sizeof(int) * width);

	if (!grid[i])
	{
	free_grid(grid, i);
	return (NULL);
	}

	for (j = 0; j < width; j++)
	grid[i][j] = 0;
	}

	return (grid);
}
