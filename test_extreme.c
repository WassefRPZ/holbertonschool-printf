#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
* main - Tests extrêmes et originaux pour _printf
*
* Return: Always 0
*/

int main(void)
{
	int len;

    int i;

	printf("\n========== TESTS EXTRÊMES _PRINTF ==========\n\n");

	/* Test 1 : Double pourcentage au sein d’un mot */
	len = _printf("%%coucou%%\n");
	printf("Test 1 : %% au milieu => Longueur : %d\n\n", len);

	/* Test 2 : Caractères spéciaux dans une chaîne */
	len = _printf("Tab\tRetour\rChariot\nSaut\vVertical\n");
	printf("Test 2 : caractères spéciaux => Longueur : %d\n\n", len);

	/* Test 3 : Mix complet d’arguments */
	len = _printf("Nom: %s, Score: %d, Caractère: %c, Pourcent: %%\n", "Alura", 100, 'X');
	printf("Test 3 : mix complet => Longueur : %d\n\n", len);

	/* Test 4 : % suivi d’un retour à la ligne */
	len = _printf("Test bizarre : %\nSuite\n");
	printf("Test 4 : %% suivi \\n => Longueur : %d\n\n", len);

	/* Test 5 : Plusieurs % successifs */
	len = _printf("%%%%%%\n");
	printf("Test 5 : 6 pourcent => Longueur : %d\n\n", len);

	/* Test 6 : Appels en boucle */
	for (i = 0; i < 5; i++)
		_printf("Test boucle n°%d\n", i);
	printf("Test 6 : Appels en boucle => Affichage manuel\n\n");

	/* Test 7 : Symbole non ASCII (UTF-8 ou accent) */
	len = _printf("Symbole spécial : é\n");
	printf("Test 7 : UTF-8 basique => Longueur : %d\n\n", len);

	printf("========== FIN TESTS EXTRÊMES ==========\n\n");

	return (0);
}
