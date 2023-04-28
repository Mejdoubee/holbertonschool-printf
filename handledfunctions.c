#include "main.h"

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
