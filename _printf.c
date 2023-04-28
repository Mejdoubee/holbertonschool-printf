#include "main.h"

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
	while (*format)
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
			else if (*format == 'i' || *format == 'd')
				total += handleWith_d_i(args);
			else if (*format == 'u')
				total += handleWith_u(args);
			else if (*format == 'o')
				total += handleWith_o(args);
			else if (*format == 'x')
				total += handleWith_x(args);
			else if (*format == 'X')
				total += handleWith_X(args);
			else if (*format == 'b')
				total += handleWith_b(args);
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
