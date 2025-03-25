#include "main.h"

/*   Fonctions pour afficher  */

/**
* print_char - Prints a character from a variadic argument list.
* @arg: The variadic argument list containing the character to print.
* Return: The number of characters printed (always 1).
*/
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
	return (1);
}

/**
* print_int - Prints an integer from a variadic argument list.
* @arg: The variadic argument list containing the integer to print.
* Return: The number of characters printed.
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
	{
		num = n;
	}

	/* Appel d'une fonction d’aide pour afficher chiffre par chiffre */
	count += print_number(num);
	return (count);
}

/**
* print_number - Helper function to print an unsigned integer.
* @num: The unsigned integer to print.
* Return: The number of characters printed.
*/
int print_number(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
* print_percent - Prints a literal percent symbol '%'.
* @arg: The variadic argument list (unused).
* Return: The number of characters printed (always 1).
*/
int print_percent(va_list arg)
{
	(void)arg;

	_putchar('%');
	return (1);
}

/**
* print_string - Prints a string from a variadic argument list.
* @arg: The variadic argument list containing the string to print.
* Return: The number of characters printed.
*/
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	int count = 0;

	if (str == NULL)
		str = "(null)";

	for (int i = 0; str[i] != '\0'; i++)

	{
		_putchar(str[i]);
		count++;
	}
	return (i);
}
