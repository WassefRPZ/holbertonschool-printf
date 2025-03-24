#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
* struct spec - Associates a format character with a function
* @specifier: The format character (e.g., 'c', 'i', 'f', 's')
* @func: Pointer to the function that handles the format
*/

typedef struct spec
{
	char *specifier;

	void (*func)(va_list);
} spec_t;

int _printf(const char *format, ...);









#endif /* MAIN_H */
