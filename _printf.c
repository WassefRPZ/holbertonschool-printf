#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: A string containing the format to print
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	/* Déclaration de la liste d'arguments variables */
	va_list args;

	/* Compteur de caractères imprimés et index de parcours */
	/* de la chaîne format */
	int count = 0, i = 0;

	/* Tableau de structures associant les spécificateurs */
	/* à leur fonction de traitement */
	spec_t spec[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'i', print_int},
		{'d', print_int}, {'\0', NULL}
	};

	/* Vérifie si le pointeur format est NULL */
	if (format == NULL)
		return (-1);

	/* Initialise l'accès aux arguments variables */
	va_start(args, format);

	/* Parcourt chaque caractère de la chaîne de format */
	while (format[i])
	{
		/* Si le caractère est un %, tenter de traiter un spécificateur */
		if (format[i] == '%')
			count += handle_specifier(format, &i, args, spec);
		else
		{
			/* Si caractère normal, l'affiche directement avec _putchar */
			_putchar(format[i]);

			/* Incrémente le nombre de caractères imprimés */
			count++;

			/* Passe au caractère suivant */
			i++;
		}
	}
	/* Termine l'utilisation de la liste d'arguments variables */
	va_end(args);

	/* Retourne le nombre total de caractères imprimés */
	return (count);
}
