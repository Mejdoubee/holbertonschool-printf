#include "main.h"

static handleWith_t array[] = {
	{'c', handleWith_c},
	{'s', handleWith_s},
	{'i', handleWith_d_i},
	{'d', handleWith_d_i},
	{'u', handleWith_u},
	{'x', handleWith_x},
	{'X', handleWith_X},
	{'o', handleWith_o},
	{'b', handleWith_b},
	{'%', handleWith_percent},
	{'\0', NULL}
};

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
	handleWith_t *handles;


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
			else
			{
				handles = array;
				while (handles->handled_format)
				{
					if (handles->handled_format == *format)
					{
						total += handles->handledfunction(args);
						break;
					}
					handles++;
				}
				if (handles->handled_format == '\0')
					_putchar('%'), _putchar(*format), total += 2;
			}
		}
		else
			_putchar(*format), total++;
		format++;
	}
	va_end(args);
	return (total);
}
