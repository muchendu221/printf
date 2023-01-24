#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int s = 0;
	va_list a;
	char *p, *start;

	params_t params = PARAMS_INIT;

	va_start(a, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, a);
		if (*p != '%')
		{
			s += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, a);
		p = get_precision(p, &params, a);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			s += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			s += get_print_func(p, a, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(a);
	return (s);
}
