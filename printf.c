#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
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
	char *temp;
	char *s;

	if (args == NULL)
		return;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

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
 * print_int - Prints an integer
 * @args: A va_list pointing to the integer to be printed
 * @count: will be incremented by the number of characters printed
 */

void print_int(va_list args, int *count)
{
    int num = va_arg(args, int);
    int i, j, power;
    int temp;
    int digits = 0;

    if (num == 0) {
        _putchar('0');
        (*count)++;
        return;
    }

    if (num < 0) {
        _putchar('-');
        num *= -1;
        (*count)++;
    }

    temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    for (i = 0; i < digits; i++) {
        power = 1;
        for (j = 0; j < digits - i - 1; j++)
            power *= 10;
        if (num == INT_MIN && i == 0) {
            _putchar((num / power) % 10 + '0' + 1);
        } else {
            _putchar((num / power) % 10 + '0');
        }
        (*count)++;
    }
}




/**
 * handle_format - Handles format specifiers for _printf
 * @traverse: Pointer to the current character in the format string
 * @args: The va_list of arguments to print
 * @count: Pointer to the count of characters printed
 */

void handle_format(const char *traverse, va_list args, int *count)
{
	int i;
	print_t prints[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{NULL, NULL}
	};

	for (i = 0; prints[i].specifier != NULL; i++)
	{
		if (*traverse == *(prints[i].specifier))
		{
			prints[i].print_func(args, count);
			break;
		}
	}

	if (*traverse == '\0')
		return;

	if (prints[i].specifier == NULL && *traverse != '\0')
	{
		_putchar('%');
		_putchar(*traverse);
		*count += 2;
	}
}

/**
 * _printf - A printf-like function that prints a formatted string
 * @format: The format string
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int count1 = 0;
	const char *traverse;

	va_list args;

	va_start(args, format);
	if (format == NULL || (strlen(format) == 1 && format[0] == '%'))
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
		handle_format(traverse, args, &count1);

		if (*traverse == '\0')
			return (-1);
	}
	va_end(args);
	return (count1);
}
