#include "main.h"

/**
* _printf - Produces output according to a format
* @format: A string containing the format to print
*
* Return: The number of characters printed (excluding the null byte)
*/

int _printf(const char *format, ...)
{
	va_list(args);

	int count = 0;

	int i = 0;

	int j = 0;

	int found = 0;

	/*char specifier; */

	spec_t spec[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int},
		{NULL, NULL}
	};

	if (format == NULL)
	return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			count++;
			i += 2;
		}

		else if (format[i] == '%')
		{
			for (j = 0; spec[j].specifier != '\0'; j++)
			{
				count += spec[j].func(args);
				i += 2;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			/* Si le spécificateur n'est pas reconnu, on affiche le % tel quel */
			_putchar('%');
			_putchar(format[i + 1]);
			count += 2;
			i += 2;
		}


		else
    	{
     		_putchar(format[i]);  /* Affiche le caractère normal */
        	count++;
			i++;
		}

	}
	return (count);


}
