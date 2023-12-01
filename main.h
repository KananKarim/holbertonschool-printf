#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>


/**
 * struct prints - Structure representing a printing specifier
 * @specifier: The format specifier associated with the printing function.
 * @print_func: Pointer to the function responsible
 */

typedef struct prints
{
	char *specifier;
	void (*print_func)(va_list args, int *count);
} print_t;

int _printf(const char *format, ...);

int _putchar(char c);
void print_char(va_list args, int *count);
void print_string(va_list args, int *count);
void print_percent(va_list args, int *count);

#endif
