#include "main.h"
/**
 * _printf - checks if there is a valid format specifier
 * @format: possible format specifier
 * Return: pointer to valid function or NULL
 */
int _printf(const char *format, ...)
{
	print_t p[] = { {"c", print_c}, {"s", print_s}, {"%", print_per},
			{"d", print_di}, {"i", print_di} };
	va_list valist;
int i = 0, c = 0, d = 0, cuenf = 0, len = 0, e = 0;
	va_start(valist, format);
	if (format == NULL)
		return (-1);
	while (format != NULL && format[i] != 0)
	{
		c = 0;
		if (format[i] == '%')
		{
			for (d = 0; d < 5; d++)
			{
				if (format[i + 1] == 0)
					return (-1);
				if (format[i + 1] == *(p[d].type))
				{
					cuenf = cuenf + p[d].func(valist);
					c = 2;
					e = e + 2;
					i = i + 1;
					break;
				}
			}
		}
		if (c == 0)
			_putchar(format[i]);
		i = i + 1;
	}
	len = i + cuenf - e;
	va_end(valist);
	return (len);
}
