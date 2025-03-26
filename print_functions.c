#include "main.h"

/**
* print_char - Prints a character
* @arg: va_list containing the character to print
*
* Return: Number of characters printed (always 1)
*/

int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
	return (1);
}

/**
* print_string - Prints a string
* @arg: va_list containing the string to print
*
* Return: Number of characters printed
*/

int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

/**
* print_percent - Prints a percent sign
* @arg: Unused va_list (ignored)
*
* Return: Number of characters printed (always 1)
*/

int print_percent(va_list arg)
{
	(void)arg;
	_putchar('%');
	return (1);
}

/**
* print_int - Prints an integer (signed)
* @arg: va_list containing the integer to print
*
* Return: Number of characters printed
*/

int print_int(va_list arg)
{
	int n = va_arg(arg, int);
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;

	count += print_number(num);
	return (count);
}

#include "main.h"

/**
* print_binary - Prints an unsigned int in binary (base 2)
* @args: va_list containing the number to convert and print
*
* Return: Number of characters printed
*/

int print_binary(va_list args)
{
	unsigned int n;

	int count = 0;

	char buffer[32];

	int i = 0, j;

	n = va_arg(args, unsigned int);

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

		while (n > 0)
		{
			buffer[i++] = (n % 2) + '0';
			n = n / 2;
		}

		for (j = i - 1; j >= 0; j--)
		{
			_putchar(buffer[j]);
			count++;
		}

	return (count);
}
