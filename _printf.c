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
* Return: count of printed char
* 1) This function prints a single character passed as an argument
* 2) increments the pointer total for track the total \
						number of characters printed
* 3) the char in taken from the var argument list using va_arg \
						cast to char , and print using _putchar
*/
int handleWith_c(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}


/**
* handleWith_s - function that handles the 's' format (string)
* @args: pointer to the current argument in the variable arg list
* Return: count of printed char
* 1) This function prints a string passed as an argument
* 2) increments the pointer total for track the total \
*						number of characters printed
* 3) the string is taken from the variable argument list using va_arg \
*			and print every single char in the string using _putchar
*/
int handleWith_s(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	while (*s)
	{
		_putchar(*s);
		count++;
		s++;
	}
	return (count);
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

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format && format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}
			else if (*format == 'c')
				total += handleWith_c(args);
			else if (*format == 's')
				total += handleWith_s(args);
			else if (*format == '%')
				_putchar('%'), total++;
			else
				_putchar('%'), _putchar(*format), total += 2;
		}
		else
			_putchar(*format), total++;
		format++;
	}
	va_end(args);
	return (total);
}
