#include "main.h"
#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* handleWith_c - function that handles the 'c' format (single char)
* @args: pointer to the current argument in the variable arg list
* @total: total is updated every time the char is printed \
			is *_/pointer/_* to the "char" 'count'
* 1) This function prints a single character passed as an argument
* 2) increments the pointer total for track the total \
						number of characters printed
* 3) the char in taken from the var argument list using va_arg \
						cast to char , and print using _putchar
*/
void handleWith_c(va_list *args, int *total)
{
	char c = (char)va_arg(*args, int);

	_putchar(c);
	(*total)++;
}


/**
* handleWith_s - function that handles the 's' format (string)
* @args: pointer to the current argument in the variable arg list
* @total: total is updated every time the char is printed \
	is *_/pointer/_* to the "char" 'count'
* 1) This function prints a string passed as an argument
* 2) increments the pointer total for track the total \
*						number of characters printed
* 3) the string is taken from the variable argument list using va_arg \
*			and print every single char in the string using _putchar
*/
void handleWith_s(va_list *args, int *total)
{
	char *s = va_arg(*args, char *);

	while (*s)
	{
	_putchar(*s);
	(*total)++;
	s++;
	}
}

/**
* _printf - function that produces output according to a format
* @format: pointer to string
* Return: the  number of characters printed
*
*/
int _printf(const char *format, ...)
{
	va_list args;
	int total = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				handleWith_c(&args, &total);
			}
			else if (*format == 's')
			{
				handleWith_s(&args, &total);
			}
			else if (*format == '%')
			{
				_putchar('%');
				total++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				total += 2;
			}
		}
		else
		{
			_putchar(*format);
			total++;
		}
		format++;
	}
	va_end(args);
	return (total);
}
