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
	int count = 0;
	int i = 0;

	spec_t spec[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'i', print_int},
		{'d', print_int}, {'\0', NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += handle_specifier(format, &i, args, spec);
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
