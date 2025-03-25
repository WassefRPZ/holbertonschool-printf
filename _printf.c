#include "main.h"

/**
* _printf - Produces output according to a format
* @format: A string containing the format to print
*
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0, j;

	spec_t spec[] = { /* Array linking specifiers to their functions */
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'i', print_int},
		{'d', print_int}, {'\0', NULL}
	};

	if (!format) /* Return -1 if format is NULL */
		return (-1);

	va_start(args, format); /* Initialize variadic arguments */
	while (format[i]) /* Loop through the format string */
	{
		if (format[i] == '%') /* Handle specifiers */
		{
			for (j = 0; spec[j].specifier; j++) /* Search for matching specifier */
				if (format[i + 1] == spec[j].specifier)
				{
					count += spec[j].func(args), i++;
					break;
				}
			if (!spec[j].specifier && format[i + 1]) /* Handle unsupported specifiers */
				count += _putchar('%') + _putchar(format[++i]);
		}
		else /* Print normal characters */
			count += _putchar(format[i]);
		i++;
	}
	va_end(args); /* Clean up variadic arguments */
	return (count); /* Return total characters printed */
}
