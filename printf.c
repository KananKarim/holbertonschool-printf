#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	_putchar(c);
	(*count)++;
}

void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	char *temp;

	for (temp = s; *temp != '\0'; temp++)
	{
		_putchar(*temp);
		(*count)++;
	}
}
void print_percent(va_list args, int *count)
{
	(void)args;
	_putchar('%');
	(*count)++;
}
