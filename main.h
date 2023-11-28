#ifndef MAIN_H
#define MAIN_H

/**
 * struct print_t - Struct for format specifiers and their corresponding functions
 * @specifier: The format specifier
 * @print_func: The function to handle the format specifier
 */

typedef struct {
    char *specifier;
    void (*print_func)(va_list args, int *count);
} print_t;

int _printf(const char *format, ...);

#endif
