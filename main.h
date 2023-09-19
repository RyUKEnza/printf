#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);

/* Custom data structure for format specifiers */
typedef struct format_specifier
{
	char flag;      /* Flag character ('+', '-', '0', ' ', or '\0' for no flag) */
	int width;      /* Minimum field width (default 0) */
	int precision;  /* Precision (default -1, meaning unspecified) */
	char length;    /* Length modifier ('h', 'l', or '\0' for none) */
	char specifier; /* Conversion specifier ('c', 's', 'd', etc.) */
} format_specifier_t;

/* Function prototypes for handling format specifiers */
int parse_format(const char *format, format_specifier_t *spec);
int print_char(va_list args, format_specifier_t *spec);
int print_string(va_list args, format_specifier_t *spec);
int print_integer(va_list args, format_specifier_t *spec);
int print_unsigned(va_list args, format_specifier_t *spec);

#endif

