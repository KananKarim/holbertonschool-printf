# Custom Printf Function in C

This repository contains a custom implementation of the printf function in C programming language. The function `_printf` is a variadic function that writes output to stdout, the standard output stream.

## Functions

The code includes the following functions:

- `print_char(va_list args)`: This function prints a character. It takes a `va_list` as an argument and prints the next argument in the list as a character.

- `print_string(va_list args)`: This function prints a string. It takes a `va_list` as an argument and prints the next argument in the list as a string.

- `print_int(va_list args)`: This function prints an integer. It takes a `va_list` as an argument and prints the next argument in the list as an integer.

- `handle_format(va_list args, char format)`: This function handles the format specifiers for `_printf`. It takes a `va_list` and a `char` as arguments and calls the appropriate function to print the next argument in the list based on the format specifier.

- `_printf(const char *format, ...)`: This is the main function that produces output. It takes a format string and a variable number of arguments, and prints the arguments according to the format string.

## Usage

To use this custom printf function, include the header file "main.h" in your program, and call the function `_printf` with a format string and a variable number of arguments.

