#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_char - Prints a character
 * @args: A va_list pointing to the character to be printed
 * @count: will be incremented by the number of characters printed
 */

void print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	_putchar(c);
	(*count)++;
}

/**
 * print_string - Prints a string
 * @args: A va_list pointing to the string to be printed
 * @count: will be incremented by the number of characters printed
 */

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

/**
 * print_percent - Prints a percent symbol
 * @args: A va_list that is not used in this function
 * @count: will be incremented by the number of characters printed
 */

void print_percent(va_list args, int *count)
{
	(void)args;
	_putchar('%');
	(*count)++;
}

/**
 * _printf - A printf-like function that prints a formatted string
 * @format: The format string
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, count1 = 0;
	const char *traverse;
	print_t prints[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (traverse = format; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%' && *traverse != '\0')
		{
			_putchar(*traverse);
			traverse++;
			count1++;
		}
		if (*traverse == '\0')
			break;
		traverse++;
		for (i = 0; prints[i].specifier != NULL; i++)
		{
			if (*traverse == *(prints[i]).specifier)
			{
				prints[i].print_func(args, &count1);
				break;
			}
		}
		if (prints[i].specifier == NULL)
		{
			_putchar(*traverse);
			count1++;
		}
	}
	va_end(args);
	return (count1);
}
