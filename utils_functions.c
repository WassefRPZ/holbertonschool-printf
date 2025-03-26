#include "main.h"

/**
* _strlen - Returns the length of a string
* @s: Pointer to the string to measure
*
* Return: Length of the string
*/

int _strlen(const char *s)
{
	int c = 0;

	while (*s++)
		c++;
	return (c);
}

/**
* _putchar - Writes a character to stdout
* @c: The character to print
*
* Return: 1 on success, -1 on error
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* print_number - Prints an unsigned integer recursively
* @n: The unsigned integer to print
*
* Return: Number of characters printed
*/

int print_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
* handle_specifier - Handles format specifier in _printf
* @format: Format string
* @i: Pointer to current index
* @args: Argument list
* @spec: Array of valid specifiers
*
* Return: Number of characters printed
*/

int handle_specifier(const char *format, int *i, va_list args, spec_t spec[])
{
	/* j : index pour parcourir le tableau spec; */
	/* count : nombre de caractères imprimés */
	int j, count = 0;

	/* Vérifie si % est le dernier caractère de la chaîne */
	/* (aucun caractère à traiter après) */
	if (format[*i + 1] == '\0')
		return (0); /* Rien à faire, on retourne 0 */

	/* Parcourt le tableau des spécificateurs jusqu'à la fin */
	/* (détectée par '\0') */
	for (j = 0; spec[j].specifier != '\0'; j++)
	{
		/* Si le caractère après % correspond à un spécificateur reconnu */
		if (format[*i + 1] == spec[j].specifier)
		{
			/* Appelle la fonction correspondante et ajoute son retour au compteur */
			count += spec[j].func(args);

			/* Avance l'index de deux positions : le '%' et le caractère suivant */
			*i += 2;

			/* Retourne le nombre de caractères imprimés */
			return (count);
		}
	}

	/* Cas : caractère non géré → afficher % + caractère */
	/* Si aucun spécificateur reconnu : on imprime '%' */
	/* suivi du caractère non reconnu */
	_putchar('%');

	/* Affiche le caractère non reconnu après '%' */
	_putchar(format[*i + 1]);

	/* Avance l'index de deux positions */
	/* (comme s’il s’agissait d’un couple valide) */
	*i += 2;

	/* Retourne 2 car deux caractères ont été imprimés : '%' */
	/* et l'autre caractère */

	return (2);
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
