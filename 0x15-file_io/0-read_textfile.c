#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a textfile and prints it to the POSIX standard out
 * Return: 0 when function fails or filename is NULL,
 * w-actual number of bytes read and printed
 * @letters: number of letters to read and print
 * @filename: textfile being read
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
	return (0);
	}
    
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
	return (0);
	}
	char *buffer = (char*) malloc(letters + 1);

	if (buffer == NULL)
	{
	fclose(file);

        return (0);
	}
    
	ssize_t read_count = fread(buffer, sizeof(char), letters, file);

	if (ferror(file))
	{
	free(buffer);
	fclose(file);

        return (0);
	}
    
	buffer[read_count] = '\0';
    
	ssize_t write_count = fwrite(buffer, sizeof(char), read_count, stdout);
	if (write_count != read_count)
	{
	free(buffer);
	fclose(file);
	return (0);
	}
    
	free(buffer);
	fclose(file);
    
	return (read_count);
}

