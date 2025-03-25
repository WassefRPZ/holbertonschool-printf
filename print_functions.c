#include "main.h"

/*   Fonctions pour afficher  */

/**
* print_char - Prints a character from a variadic argument list.
* @arg: The variadic argument list containing the character to print.
*/

int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	_putchar(c);
	return (0);
}

/**
* print_int - Prints an integer from a variadic argument list.
* @arg: The variadic argument list containing the integer to print.
*/

int print_int(va_list arg)
{
	int n = va_arg(arg, int);
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	/* Appel d'une fonction d’aide pour afficher chiffre par chiffre */
	print_number(num);
	return (0);
}

/**
* print_percent - Prints a literal percent symbol '%'.
* @arg: The variadic argument list (unused).
*
* Description: This function handles the '%%' format specifier
*              in _printf. It prints a single '%' character.
*/

int print_percent(va_list arg)
{
	(void)arg;

	_putchar('%');
	return (0);
}

/**
* print_string - Prints a string from a variadic argument list.
* @arg: The variadic argument list containing the string to print.
*/

int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (0);
}
