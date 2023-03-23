#ifndef _VARIADIC_H_
#define _VARIADIC_H_

#include <stdarg.h>

/**
 * struct print_format - Struct for print formats
 * @type: The format type
 * @func: The function pointer to the print function
 */
typedef struct print_format
{
	char *type;
	void (*func)(va_list);
}	print_format_t;

	int _putchar(char c);
	int sum_them_all(const unsigned int n, ...);
	void print_numbers(const char *separator, const unsigned int n, ...);
	void print_strings(const char *separator, const unsigned int n, ...);
	void print_all(const char * const format, ...);

	#endif

