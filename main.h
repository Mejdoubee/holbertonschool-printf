#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
* struct handleWith - Structure for handling format specifiers
* @hand: Format specifier character
* @f: Function pointer to the corresponding handler function for the format specifier
*
*/
typedef struct handleWith
{
	char hand;
	int (*f)(va_list args);
} handleWith_t;


int _printf(const char *format, ...);
int _putchar(char c);
int handleWith_d_i(va_list args);
int handleWith_s(va_list args);
int handleWith_c(va_list args);
int handleWith_u(va_list args);
int handleWith_o(va_list args);
int handleWith_x(va_list args);
int handleWith_X(va_list args);
int handleWith_b(va_list args);

#endif
