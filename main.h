#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

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

#endif
