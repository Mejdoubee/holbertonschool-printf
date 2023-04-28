#include "main.h"

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
* handleWith_u - function that handles the 'u' format (unsigned int)
* @args: pointer to the current argument in the variable arg list
* Return: count of printed char
*
*/
int handleWith_u(va_list args)
{
	unsigned long n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[11];
	char *ptr = &buffer[10];
	*ptr = '\0';
	ptr--;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		*ptr = (n % 10) + '0';
		n /= 10;
		ptr--;
		count++;
	}
	ptr++;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	return (count);
}

/**
* handleWith_o - function that handles the 'o' format (octal)
* @args: pointer to the current argument in the variable arg list
* Return: count of printed char
*
*/

int handleWith_o(va_list args)
{
	unsigned long n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[12];
	char *ptr = &buffer[11];

	*ptr = '\0';
	ptr--;
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		*ptr = (n % 8) + '0';
		n /= 8;
		ptr--;
		count++;
	}
	ptr++;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	return (count);
}

/**
* handleWith_x - function that handles the 'x' format (hexa)
* @args: pointer to the current argument in the variable arg list
* Return: count of printed char
*
*/

int handleWith_x(va_list args)
{
	unsigned long n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[9];
	char *ptr = &buffer[8];

	*ptr = '\0';
	ptr--;
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		if ((n % 16) < 10)
		{
			*ptr = (n % 16) + '0';
		}
		else if ((n % 16) < 17)
		{
			*ptr = (n % 16) + 'a' - 10;
		}
		n /= 16;
		ptr--;
		count++;
	}
		ptr++;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	return (count);
}

/**
* handleWith_X - function that handles the 'X' format (Hexa upper)
* @args: pointer to the current argument in the variable arg list
* Return: count of printed char
*
*/
int handleWith_X(va_list args)
{
	unsigned long n = va_arg(args, unsigned int);
	int count = 0;
	char buffer[9];
	char *ptr = &buffer[8];

	*ptr = '\0';
	ptr--;
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		if ((n % 16) < 10)
		{
			*ptr = (n % 16) + '0';
		}
		else if ((n % 16) < 17)
		{
			*ptr = (n % 16) - 10 + 'A';
		}
		n /= 16;
		ptr--;
		count++;
	}
	ptr++;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	return (count);
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

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		_putchar(*s);
		count++;
		s++;
	}
	return (count);
}

/**
* handleWith_d_i - function that handles the 'i and d' format (signed integer)
* @args: pointer to the current argument in the variable arg list
* Return: count of printed char
*
*/
int handleWith_d_i(va_list args)
{
	long int n = va_arg(args, int);
	int count = 0;
	char buffer[12];
	char *ptr = &buffer[11];
	*ptr = '\0';
	ptr--;

	if (n == 0)
	{
		*ptr = '0';
		_putchar(*ptr);
		return (1);
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		count++;
	}
	while (n > 0)
	{
		*ptr = (n % 10) + '0';
		n /= 10;
		ptr--;
		count++;
	}
	ptr++;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	return (count);
}

/**
* handleWith_b - function that handles the 'b' format (dec to bin)
* @args: pointer to the current argument in the variable  arg list
* Return: count of printed char
*
*/
int handleWith_b(va_list args)
{
	unsigned long n = va_arg(args, unsigned int);
	int count = 0;
	char *buffer, *ptr;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while ((n >> count) != '\0')
	{
		count++;
	}
	buffer = malloc((count + 1) * sizeof(char));
	if (buffer == NULL)
	{
		return (-1);
	}
	ptr = buffer + count;
	*ptr = '\0';
	ptr--;

	while (n > 0)
	{
		*ptr = (n % 2) + '0';
		n /= 2;
		ptr--;
		count++;
	}
	ptr++;
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}
	free(buffer);
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
