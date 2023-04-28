#include "main.h"

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
