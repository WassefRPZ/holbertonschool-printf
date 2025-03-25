#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point for testing the custom _printf function
 *
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	/* Test chaîne vide */
	len1 = _printf("");
	len2 = printf("");
	printf("Résultats (vide) : %d | %d\n", len1, len2);

	/* Test de base avec %c et %s */
	len1 = _printf("Lettre : %c, Mot : %s\n", 'A', "Bonjour");
	len2 = printf("Lettre : %c, Mot : %s\n", 'A', "Bonjour");
	printf("Résultats : %d | %d\n", len1, len2);

	/* Test de %% */
	len1 = _printf("Pourcentage : %%\n");
	len2 = printf("Pourcentage : %%\n");
	printf("Résultats : %d | %d\n", len1, len2);

	/* Test NULL string */
	len1 = _printf("Chaîne : %s\n", NULL);
	len2 = printf("Chaîne : %s\n", NULL);
	printf("Résultats (NULL) : %d | %d\n", len1, len2);

	/* Test %i et %d */
	len1 = _printf("Nombres : %i et %d\n", -42, 1024);
	len2 = printf("Nombres : %i et %d\n", -42, 1024);
	printf("Résultats : %d | %d\n", len1, len2);

	/* Test % inconnu */
	len1 = _printf("Test inconnu : %r\n");
	len2 = printf("Test inconnu : %r\n");
	printf("Résultats : %d | %d\n", len1, len2);

	/* Test extrême */
	len1 = _printf("Max int : %d, Min int : %d\n", INT_MAX, INT_MIN);
	len2 = printf("Max int : %d, Min int : %d\n", INT_MAX, INT_MIN);
	printf("Résultats : %d | %d\n", len1, len2);

	return (0);
}
