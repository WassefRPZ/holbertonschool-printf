#include "main.h"

/**
* _strlen - returns the length of a string.
*@s: Pointer to the string to be measured
*
* Return: The length of the string
*/

int _strlen(const char *s)
{
	int c = 0;

	while (*s++)
		c++;
	return (c);
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
*         On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_number - Prints an unsigned integer using _putchar.
* @n: The unsigned integer to print.
*
* Return: The number of characters printed.
*/

int print_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
	count += print_number(n / 10);

	_putchar((n % 10) + '0');
	return (count);
}

/**
* handle_specifier - Handles a format specifier in a printf-like function.
* @format: The format string.
* @i: Pointer to the current position in the format string.
* @args: The list of arguments to process.
* @spec: Array of spec_t structures containing specifier-function mappings.
*
* Return: The number of characters printed.
*/

int handle_specifier(const char *format, int *i, va_list args, spec_t spec[])
{
	int j, count = 0;

	for (j = 0; spec[j].specifier != '\0'; j++)
	{
		if (format[*i + 1] == spec[j].specifier)
		{
			count += spec[j].func(args);
			*i += 2;
			return (count);
		}
	}
	_putchar(format[*i]);
	(*i)++;
	return (1);
}

/**
* convert - Converts a number to a string in the specified base.
* @num: The number to convert.
* @base: The numerical base to use
* (e.g., 2 for binary, 10 for decimal, 16 for hexadecimal).
*
* @lowercase: If non-zero, use lowercase letters for hexadecimal digits (a-f);
* otherwise, use uppercase (A-F).
*
* Return: A pointer to a statically allocated buffer
*		  containing the converted string.
*		  The caller should not modify or free this buffer.
*/

/* convert n'est pas encore codée, on neutralise les paramètres */
char *convert(unsigned long int num, int base, int lowercase)
{
	(void)num;
	(void)base;
	(void)lowercase;

	return (NULL);
}
