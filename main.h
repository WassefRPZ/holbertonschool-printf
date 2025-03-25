#ifndef MAIN_H
#define MAIN_H

/* ========== 1. Bibliothèques nécessaires ========== */

#include <stdarg.h> /* Pour va_list, va_start, etc. */
#include <stdlib.h> /* Pour malloc et free */
#include <stddef.h> /* Pour NULL */
#include <unistd.h> /* Pour write */

/* ========== 2. Structures ========== */

/**
* struct spec - Associates a format character with a function
* @specifier: The format character (e.g., 'c', 'i', 'f', 's')
* @func: Pointer to the function that handles the format
*/

typedef struct spec
{
	char specifier;

	int (*func)(va_list);
} spec_t;

/* ========== 3. Prototypes des fonctions principales ========== */

/* Fonction principale recréer */

int _printf(const char *format, ...);

/* ========== 4. Prototypes des fonctions de gestion des types ========== */

/* Fonctions de base */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/* Fonctions pour les entiers */
int print_int(va_list args);
int print_unsigned(va_list args);

/* Fonctions pour les conversions numériques */
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);

/* Fonctions pour autres types */
int print_pointer(va_list args);
int print_rev(va_list args);
int print_rot13(va_list args);


/* ========== 5. Prototypes des fonctions utilitaires ========== */

int _putchar(char c);

char *convert(unsigned long int num, int base, int lowercase);

int _strlen(const char *s);

int print_number(unsigned int n);

int handle_specifier(const char *format, int *i, va_list args, spec_t spec[]);

/* void *_memcpy(void *dest, const void *src, unsigned int n); */

#endif /* MAIN_H */
