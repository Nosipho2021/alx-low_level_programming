#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - Reads and prints a text file to standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed
 * 0 on failure (file cannot be opened, read, or other errors)
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
	return (0);
	}

	int file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
	{
	return (0);
	}

	char *buffer = (char *)malloc(letters);

	if (buffer == NULL)
	{
	close(file_descriptor);
	return (0);
	}

	ssize_t bytesRead = read(file_descriptor, buffer, letters);

	if (bytesRead == -1)
	{
	free(buffer);
	close(file_descriptor);
	return (0);
	}

	ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	if (bytesWritten == -1 || (size_t)bytesWritten != bytesRead)
	{
	free(buffer)
	close(file_descriptor);
	return (0);
	}

	free(buffer);
	close(file_descriptor);
	return (bytesRead);
}

